package workbook;

import java.util.Scanner;

public class p1425 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int a=input.nextInt();
		int b=input.nextInt();
		int c=input.nextInt();
		int d=input.nextInt();
		input.close();
		int m=c-a;
		int n=d-b;
		if(n<0) {
			m--;
			n+=60;
		}
		System.out.print(m+" "+n);
}
}