package workbook;

import java.util.Scanner;

public class p1152 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		int num[]=new int[n];
		int temp=0;
		int vis[]=new int [n-1];
		int count=0;
		for(int i=0;i<num.length;i++)
			num[i]=input.nextInt();
		for(int i=0;i<vis.length;i++)
			vis[i]=(i+1);
		for(int i=0;i<num.length-1;i++)
		{
			temp=Math.abs(num[i+1]-num[i]);
			for(int j=0;j<vis.length;j++)
				if(temp==vis[j]&&vis[j]!=0)
				{
					vis[j]=0;
					count++;
				}
		}
		if(count==vis.length)
			System.out.print("Jolly");
		else
			System.out.print("Not jolly");
		input.close();
	}

}
