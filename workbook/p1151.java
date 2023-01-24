package workbook;

import java.util.Scanner;

public class p1151 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
//		Scanner input = new Scanner(System.in);
//		int m = input.nextInt();
//		int num[] = new int[4];
//		int count=0;
//		input.close();
//		for(int i=10000; i<=30000; i++)
//		{
//			for(int j=0;j<3;j++)
//			{
//				num[j]=num[3]%1000;
//				num[3]/=10;
//				if(num[j]%m==0)
//					count++;
//			}
//			if(count==3)
//			{
//				System.out.println(i);
//				count=0;
//			}
//			
//		}
		Scanner input = new Scanner(System.in);
		int k = input.nextInt();
		input.close();
		String num1, num2,num3,num;
		int count=0;
		for(int i=10000; i<=30000; i++)
		{
			num=String.valueOf(i);
			num1=num.substring(0, 3);
			num2=num.substring(1, 4);
			num3=num.substring(2, 5);
			if(Integer.valueOf(num1)%k==0&&Integer.valueOf(num2)%k==0&&Integer.valueOf(num3)%k==0)
			{
				System.out.println(i);
				count++;
			}
		}
		if(count==0)
			System.out.print("No");
	}

}
//static Integer valueOf(int i)
//static Integer valueOf(String s)
//static Integer valueOf(String s, int radix)
//i -- Integer 对象的整数。
//s -- Integer 对象的字符串。
//radix --在解析字符串 s 时使用的进制数，用于指定使用的进制数。
//Integer valueOf(int i)：返回一个表示指定的 int 值的 Integer 实例。
//Integer valueOf(String s):返回保存指定的 String 的值的 Integer 对象。
//Integer valueOf(String s, int radix): 返回一个 Integer 对象，该对象中保存了用第二个参数提供的基数进行解析时从指定的 String 中提取的值。
//public String substring(int beginIndex)或public String substring(int beginIndex, int endIndex)
//beginIndex -- 起始索引（包括）, 索引从 0 开始。
//endIndex -- 结束索引（不包括）。