package workbook;

import java.util.Scanner;

public class p1089 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
			Scanner input = new Scanner(System.in);
			int count=0;
			int money=300;
			int p=0;
			for(int i=0;i<12;i++)
			{
				int m=input.nextInt();
				money=money-m;
				if(money<0)
				{
					System.out.print("-"+(i+1));
					p=0;
					break;
				}
				else
				{
					count+=money/100;
					money%=100;
					p=1;
				}
				money+=300;
			}
			if(p==1)
			System.out.print((count*100*1.2+money-300));
			input.close();
	}
		
}
