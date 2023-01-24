package workbook;

import java.util.Scanner;

public class p1615 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		String[] tim_1 = input.nextLine().split(":");
		String[] tim_2 = input.nextLine().split(":");
		long n = input.nextInt();
		input.close();
		long hour=Integer.valueOf(tim_2[0])-Integer.valueOf(tim_1[0]);
		long minter=Integer.valueOf(tim_2[1])-Integer.valueOf(tim_1[1]);
		long second=Integer.valueOf(tim_2[2])-Integer.valueOf(tim_1[2]);
		n*=(hour*60*60+minter*60+second);
		System.out.print(n);
	}

}
