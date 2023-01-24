package workbook;

import java.util.Scanner;

public class p1482 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String[] num_1 = new String[] {};
		String[] num_2 = new String[] {};
		Scanner input = new Scanner(System.in);
		num_1=input.nextLine().split("/");
		num_2=input.nextLine().split("/");
		input.close();
		int num_3=Integer.valueOf(num_1[0])*Integer.valueOf(num_2[0]);
		int num_4=Integer.valueOf(num_1[1])*Integer.valueOf(num_2[1]);
		for(int i=2;i<=num_4;i++) {
			if(num_3%i==0&&num_4%i==0) {
				num_3/=i;
				num_4/=i;
				i=1;
			}
		}
		System.out.print(num_3+" "+num_4);
	}

}
