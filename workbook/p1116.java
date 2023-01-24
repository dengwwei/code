package workbook;

import java.util.Scanner;

public class p1116 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int m = input.nextInt();
		int num[] = new int[10001]; 
		for(int i=0;i<m;i++)
			num[i]=input.nextInt();
		input.close();
		int temp=0;
		int count=0;
		for(int j=0;j<m-1;j++)
		for(int i=0;i<m-1;i++)
		{
			if(num[i]>num[i+1])
			{
				temp=num[i];
				num[i]=num[i+1];
				num[i+1]=temp;
				count++;
			}
		}
		System.out.print(count);
	}

}
