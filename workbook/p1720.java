package workbook;

import java.util.Scanner;

public class p1720 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		input.close();
		double num_1 = Math.pow((1 + Math.sqrt(5)) / 2.0, n);
		double num_2 = Math.pow((1 - Math.sqrt(5)) / 2.0, n);
		double num = (num_1 - num_2) / Math.sqrt(5);
		System.out.print(String.format("%.2f", num));
	}

}
