package workbook;

import java.util.Scanner;

public class p1317 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int[] num = new int [input.nextInt()];
		for(int i=0;i<num.length;i++)
			num[i]=input.nextInt();
		int count=0;
		for(int i=1;i<num.length-1;i++)
		{
			if(num[i]<num[i+1]&&num[i]<num[i-1])
				count++;
			if(num[i]==num[i+1])
				if(num[i+1]<num[i+2])
					count++;
		}
		input.close();
		System.out.print(count);
		}	
}
