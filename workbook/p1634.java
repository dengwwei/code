package workbook;

import java.util.Scanner;

public class p1634 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int x = input.nextInt();
		int n = input.nextInt();
		input.close();
		long sum=1;
		for(int i=0;i<n;i++) {
			sum+=sum*x;
		}
		System.out.print(sum);
	}

}
