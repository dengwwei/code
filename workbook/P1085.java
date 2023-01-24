package workbook;

import java.util.Scanner;

public class P1085 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int m=0,n=0,count=0,p=0;
		for(int i=1;i<8;i++)
		{
			m=input.nextInt();
			n=input.nextInt();
			if((m+n)>8&&(m+n)>count)
			{
				count=m+n;
				p=i;
			}
		}
		input.close();
		System.out.print(p);
	}

}
