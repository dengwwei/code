package workbook;

import java.util.Scanner;


public class p1075 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
			Scanner input=new Scanner(System.in);
			int n=input.nextInt();

			int count=0;
			for(int i=2;i*i<=n;i++)
			{
				if(n%i==0)
				{
						count=Math.max(count, i);
				}
			}
			input.close();
			System.out.print(n/count);
	}

}
//for循环经历时间尽可能缩短
