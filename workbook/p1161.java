package workbook;

import java.util.Scanner;

public class p1161 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int lamp[] = new int [2000001];
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		int ti=0,p=0;
		double ai=0.00;
		for(int i=0;i<n;i++)
		{
			ai = input.nextDouble();
			ti = input.nextInt();
			for(int j=0;j<ti;j++)
			{
				p=(int)(ai*(j+1));
				if(lamp[p]==0)
					lamp[p]=1;
				else 
					lamp[p]=0;
			}
		}
		input.close();
		for(int i=0;i<lamp.length;i++)
			if(lamp[i]==1)
			{
				System.out.print(i);
				break;
			}
	}

}
