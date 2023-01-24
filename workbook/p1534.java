package workbook;

import java.util.Scanner;

public class p1534 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		int count=0;
		int sum=0;
		for(int i=0;i<n;i++) {
			int num_1=input.nextInt();
			int num_2=input.nextInt();
//			if(count>=0) {
//			sum=count+num_1+num_2;
//			}
//			else {
//				sum=num_1+num_2;
//			}
//			count=sum-8;
			sum+=num_1+num_2-8;
			count+=sum;
		}
		input.close();
		System.out.print(count);
	}

}
