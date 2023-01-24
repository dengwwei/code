package workbook;

import java.util.Scanner;

public class p1909 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int sum_amo=0,sum_p=0,minn=999999999;
		for(int i=0;i<3;i++) {
			int amo=input.nextInt();
			int price = input.nextInt();
			do {
				sum_amo+=amo;
				sum_p+=price;
			}while(sum_amo<n);
			if(sum_p<minn)
				minn=sum_p;
			sum_p=sum_amo=0;
		}
		input.close();
		System.out.println(minn);
	}

}
