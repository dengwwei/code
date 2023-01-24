package workbook;

import java.util.Scanner;

public class p1980 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int x = input.nextInt();
		String str;
		int count = 0;
		for (int i = 1; i <= n; i++) {
			str = String.valueOf(i);
			for (int j = 0; j < str.length(); j++) {
				if (str.charAt(j)-48 == x)
					count++;
			}
		}
		input.close();
		System.out.println(count);
	}

}
