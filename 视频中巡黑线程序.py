'''
巡线

使用多重策略，利用现有视觉识别功能在画面中识别黑线，并根据黑线轨迹移动。
识别策略：
    1.剪裁画面：
        小车使用固定位置的广角镜头。虽然视角大，但对于巡线来说，前方和上方的画面是无效且影响使用的。
        所以画面剪裁至，只保留向下角度的画面范围。
    2.调节感光器参数：
        1）固定亮度和白平衡，以保证阈值的参考对象是不变的。
        2）固定帧速。因为巡线多为室内，自动帧速机制通常会降低帧速以提高亮度。巡线程序在搜寻黑线时，
           并不需要很高的亮度，所以固定通过固定帧速提高运行速度。
        3）提高画面对比度和饱和度，增加黑白色差，方便搜寻黑线。
    3.分段切割，定位黑线偏移量
        以横线切割，将画面分为6个区域。在每个区域分别检测黑线所在的x轴位置值。再综合计算整条黑线的
        偏移角度。
    4.自动调节阈值：
        在上述每个区域内，如果检测到多个黑色目标，则收束阈值，直到目标唯一，或到阈值限制范围。如果
        依然检测到多个目标，则按面积最大的目标为准。
    5.画面显示：
        显示部分使用了高速模式2（160*120）的画面尺寸。由于画面经过剪裁使用，所以在屏幕上有充分的
        空间显示多个不同的画面副本。屏幕分别显示了原版画面、识别结果方框标识图、阈值二值化(单色化)
        画面。
黑线布置：
    例程以全速为基准速度，所以对场地要求较高。如果场地不满足以下要求，可调低速度参数再尝试。
    建议使用黑色PVC绝缘胶带(推荐3M品牌)。可以设置弧形弯、直角、十字交叉路口。
    要求：弧形弯最小半径10cm，直角边长最小20cm，十字交叉尽量保持垂直。
    （大于以上参数更佳，弧线曲率不均匀时，出现半径小于10cm的弧线，可能无法使用。）

作者网店&联络：shop111000005.taobao.com
20210828
'''
import sensor, image, time, car, text,pid   #导入库
screen=car.screen() #声明屏幕
img=sensor.snapshot()   #声明图像
img.clear() #图形清空
#文字提示
text.word(img,90,0,'巡线')
text.paragraph(img,0,18,'建议在浅色台面,使用黑色PVC绝缘胶带(推荐3M)布置轨迹线.',first_line_indent=2)
text.paragraph(img,0,18*3,'轨迹线可包含弧线弯、直角弯、十字路口.弧线最小半径大于10厘米,直角边长大于20厘米,十字路口直线部分大于20厘米且保持垂直.',first_line_indent=2)
text.paragraph(img,0,126,'因为程序参数默认为全速行驶,所以对场地要求较高.场地不能满足上述要求可以尝试修改程序参数.',first_line_indent=2)
text.paragraph(img,0,126+18*3,'按下继续后等待2秒,系统自动校准亮度/白平衡.',color=(255,50,50),first_line_indent=2)
b_continue=car.touch_button(252,198,40,20)  #声明按键
text.word(img,254,198,'继续')
while not b_continue.state(img):    #等待按下继续键
    screen.display(img)

led=car.led()   #声明led
led.turn_on()   #开启led
#感光器设置
screen.high_speed_mode(2)   #屏幕高速模式2（160*120画幅）
sensor.set_framesize(sensor.QVGA)   #感光器QVGA（320*240）分辨率
sensor.set_pixformat(sensor.GRAYSCALE)  #感光器黑白模式
sensor.skip_frames(time = 2000) #等待2秒感光器校准亮度/白平衡
sensor.set_auto_gain(False) #锁定自动亮度
sensor.set_auto_whitebal(False) #锁定自动白平衡
sensor.set_windowing(0,180,320,60)  #剪裁画面
midpoint=160    #设置画面x轴向中值
sensor.set_auto_exposure(False,exposure_us=4000)    #设置固定帧速
sensor.set_contrast(3)  #设置对比度，范围-3~3
sensor.set_saturation(3)    #设置饱和度，范围-3~3

img_display = sensor.alloc_extra_fb(160,120,sensor.RGB565)#创建一个和屏幕尺寸相同的画布
img_signle = sensor.alloc_extra_fb(160,60,sensor.GRAYSCALE)#创建一个画面剪裁缩放后尺寸的黑白画布

drive=car.drive()   #声明普通驱动
d_close=car.drive_close_loop()  #声明闭环驱动
d_close.lock_degrees(False) #关闭闭环驱动的锁止电机角度
clock = time.clock()    #声明时钟，用于获取帧速
pid_x=pid.PID(p=1.1,i=0.8,d=0.01,imax=40)   #声明用于小车平移的PID
pid_turn=pid.PID(p=1.6,i=0,d=0.015) #声明用于小车转向的PID

threshold=[[0,128],[0,128],[0,128],[0,128],[0,128],[0,128]]#创建阈值变量

move_x=0    #平移变量
move_turn=0 #转向变量
line_point=[0,0,0,0,0,0]    #记录六个线的x轴点
line_area=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]#记录六个识别块的参数
line_none=0 #记录没有发现黑线段的次数
stop_count=0    #停止前延迟计数
#主循环
while True:
    #clock.tick()    #用于统计帧速的程序，取消注释可用
    img = sensor.snapshot() #获取感光器画面
    for n in range(0,6):    #循环6次，分别对应画面被分割的6各区域
        threshold[n]=[0,80] #默认阈值为0~80。黑白画面，阈值只需要最小值和最大值即可。
        while True: #自动收束阈值的循环
            #按阈值寻找色块，roi是有效区，根据上一级for循环而定，
            #x_stride、y_stride、pixels_threshold分别是过滤掉的x轴、y轴、面积尺寸。
            blobs = img.find_blobs([threshold[n]],roi=(0,n*10,320,10),\
                    x_stride=5,y_stride=5,pixels_threshold=50)#设置过滤长或宽小于5,像素小于50的色块
            if blobs:   #如果有结果
                if len(blobs)>1:    #多个结果
                    if threshold[n][1]>20:  #阈值大于20之前
                        threshold[n][1]-=5  #每次减5（收束阈值）
                    else:   #阈值等于20了还有多个结果
                        break   #跳出
                else:   #只有一个结果
                    break   #跳出
            else:   #没有结果
                break   #跳出
        if blobs:#如果有识别结果
            blob=max(blobs, key = lambda b: b.pixels())#在识别结果中，以面积(像素)为依据，找最大值。
            line_area[n]=blob.rect()    #记录当前色块所在区域
            line_point[n]=blob.cx()-midpoint    #记录色块的中心点
            #如果色块宽度在画面宽度的0.375到0.875之间（角度很大的弧线或直角）
            #注：下面数值是以画面一般的数值作为基数计算，所以相对于完整画面，数值在37.5%到87.5%之间。
            if midpoint*0.75<blob.w()<midpoint*1.75:
                line_point[n]=line_point[n]*2
        else:
            line_area[n]=-1 #没有识别到结果装填一个负值，在后文可以判断是否识别到了结果
            line_point[n]=-500
    #小车屏幕所显示的内容
    img_signle.draw_image(img,0,0,x_scale=0.5,y_scale=0.5)#将识别画面，长宽各缩小50%，绘入备用画布2中
    img_display.clear() #备用画布1清空
    img_display.draw_image(img_signle,0,0)  #备用画布2的内容绘入备用画布1（此处绘制的是屏幕上第一部分,原始画面）

    for n in range(6):  #循环6次，分别处理6段的显示
        if line_area[n]!=-1:    #如果识别结果方块有数据
            #在相应位置画方块。此处绘制的是屏幕上第二部分，识别结果画面。
            img_display.draw_rectangle(int(line_area[n][0]/2),int(line_area[n][1]/2)+80,int(line_area[n][2]/2),int(line_area[n][3]/2),color=(255,0,0))
        if n>0 and line_area[n]!=-1 and line_area[n-1]!=-1:#如果不是第一个点，且前后的点有数据
            #在识别到的黑线中心画线。此处绘制的是屏幕上第二部分，识别结果画面。
            img_display.draw_line(int((line_point[n]+midpoint)/2) , n*5+82 , int((line_point[n-1]+midpoint)/2) , n*5+77)
        #每一段按阈值二值化(单色)显示。此处绘制的是屏幕上第三部分，二值化（单色）画面
        img_display.draw_image(img_signle.copy(roi=(0,n*5,160,5)).binary([threshold[n]]),0,n*5+40)

    img_display.draw_rectangle(0,0,160,30,color=(0,0,255))  #画三个方框，标示屏幕显示的三个区域。
    img_display.draw_rectangle(0,40,160,30,color=(0,0,255))
    img_display.draw_rectangle(0,80,160,30,color=(0,0,255))

    screen.display(img_display) #在屏幕显示画面

    #计算黑线数值
    #以从下到上的第一个数值为基准平移，保障第一个块在屏幕中心。
    #以所有块的数值的平均值计算黑线斜率
    line_none=0 #记录没有发现黑线段的次数
    #倒叙循环6次。因为画面的坐标系是从上到下，而小车行进从下到上处理比较方便。
    #此处查询从下到上的第一个有效数值，并记录
    for n in range(5,-1,-1):
        if line_point[n]>-500:  #如果之前获取到了数值
            move_x=line_point[n]    #记录到平移
            move_turn=line_point[n] #记录到旋转
            break   #跳出for循环
    #此处将所有分段中识别到的坐标作平均值，计算黑线的斜率
    for n in range(5,-1,-1):
        if line_point[n]>-500:  #如果有数值
            move_turn=(move_turn+(line_point[n]))/2 #累加再除2取平均值
        else:
            line_none+=1#如果没有数值记录累加1

    #执行移动
    if line_none<5: #黑线识别分为6段，未发现黑线小于5，则发现黑线2次或更多，即认为有效
        stop_count=0    #用于停止的计次归零
        #将上述平移、转向量，装入对应的PID模块，得到执行结果给驱动模块。
        #PID模块中第二个参数位，是输出结果的比例系数。这里填1，而去修改PID分别的系数即可。
        drive.move(pid_x.get_pid(move_x,1),100,pid_turn.get_pid(move_turn,1))
    else:   #如果黑线小于两段
        stop_count+=1   #累加用于停止的计次
        if stop_count>20:   #连续20次黑线小于2段
            drive.move(0,0,0)   #停止移动
            pid_x.reset_I() #重置PID的I，避免累加过量
            pid_turn.reset_I()
    #print(clock.fps())  #打印帧速，方便在编程软件中调试。取消注释可用
