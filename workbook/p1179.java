package workbook;

import java.util.Scanner;



public class p1179 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		long m=input.nextLong();//2
		long n=input.nextLong();//22
		long p=0;
		int count=0;
		for(long i=m;i<=n;i++)//m=2,n=22
		{
			p=i;
			while(p!=0) {//12 2 1 22  2
				if(p%10==2)
					count++;
				p/=10;
			}
			
		//equals(Object anObject)
		}
		input.close();
		System.out.print(count);
}
}
