package workbook;

import java.util.Scanner;

public class p1420 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		int m=input.nextInt();
		int num=m;
		int count=0;
		int max=0;
		for(int i=0;i<n-1;i++)
		{
			m=input.nextInt();
			if(num+1==m) {
				count++;
				if(max<count)
					max=count;
			}
			else {
				count=0;
			}
			num=m;
		}
		System.out.print(max+1);
		input.close();
	}

}
