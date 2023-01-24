package workbook;

import java.util.Scanner;

public class p1421 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n =input.nextInt();
		int m = input.nextInt();
		input.close();
		n=n*10+m;
		System.out.print(n/19);
	}

}
