'''
这是一个早期巡红线版本的程序
程序没有完成全部注释，也没有整合显示
并且，此次共享前，也没有二次测试
所以程序仅供参考
'''
import sensor, image, time, car, text,pid

screen=car.screen(high_speed=2)
#sensor.set_framesize(sensor.QVGA)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
midpoint=160
sensor.set_windowing(0,180,320,60)
sensor.set_auto_exposure(False,exposure_us=5000)    #设置帧速
#sensor.set_gainceiling(2)
sensor.set_contrast(3)  #设置对比度
sensor.set_saturation(3)    #饱和度
#sensor.set_brightness(3)    #设置亮度

#sensor.set_auto_gain(False)

led=car.led()
led.turn_on()

drive=car.drive()
d_close=car.drive_close_loop()
d_close.lock_degrees(False)
clock = time.clock()
line=None
pid_x=pid.PID(p=0.8,i=0,d=0,imax=40)
pid_turn=pid.PID(p=1.5,i=0,d=0.01,imax=40)

threshold_red=(40, 62, 50, 90, -15, 80) #红线阈值

move_x=0
#move_x_kp=0.5
move_turn=0
#move_turn_kp=0.9
line_point=[0,0,0,0,0,0]    #记录六个线的x轴点
line_none=0 #累加6次为 没发现线
stop_count=0    #停止前延迟计数
while(True):
    clock.tick()
    img = sensor.snapshot()
    #img.gamma_corr(contrast=4)#伽马值
    img.binary([threshold_red])   #按阈值二值化
    for n in range(6):#6
        blobs = img.find_blobs([(95,100)],roi=(0,50-n*10,320,10))
        if blobs:
            blob=max(blobs, key = lambda b: midpoint*2-abs(b[5]-midpoint))
            line_point[n]=blob.cx()-midpoint
            #print(blob)
            #print('原'+str(line_point[n]))
            if midpoint*0.75<blob.w()<midpoint*1.75:
                line_point[n]=line_point[n]*2
                print('增加'+str(line_point[n]))
            img.draw_rectangle(blob.rect(),color=(0,0,255))
            if n>0 and line_point[n-1]>0:
                img.draw_line(line_point[n-1]+midpoint,55-(n-1)*10,line_point[n]+midpoint,55-n*10,color=(0,0,255))
        else:
            line_point[n]=-500
    #print(line2_point)
    #计算线的关键点平均值
    line_none=0
    for n in range(6):
        if line_point[n]>-500:
            move_turn=(move_turn+(line_point[n]))/2
        else:
            line_none+=1
    #执行移动
    if line_none<5: #巡线点大于两个数据
        stop_count=0
        move_x=line_point[0]
        move_x=pid_x.get_pid(move_x,1)
        move_turn=pid_turn.get_pid(move_turn,1)
        drive.move(move_x,100,move_turn )
        print(move_turn)
    else:
        stop_count+=1
        if stop_count>20:
            drive.move(0,0,0)
            pid_x.reset_I()
            pid_turn.reset_I()
    #line = img.get_regression([(200,255)], robust = True,x_stride=5,y_stride=5)
    #if line:
    #    print(line)
    #    img.draw_line(line.line(), color = 127,thickness=2)
    #    if line.y1()<line.y2():
    #        move_turn=(line.x1()-line.x2())*move_turn_kp
    #    else:
    #        move_turn=(line.x2()-line.x1())*move_turn_kp

        #drive.move(move_x*move_x_kp,40, move_turn)
    #else:
    #    drive.move(0,0,0)
    screen.display(img)
    print(clock.fps())
