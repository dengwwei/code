package workbook;

import java.util.Scanner;

public class p1150 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		long n=input.nextLong();
		long k=input.nextLong();
		input.close();
		long count=n;
		while(n>=k)
		{
			count+=n/k;
			n=n%k+n/k;
		}
		System.out.print(count);
//		System.out.print(n+(n-1)/(k-1));
	}

}
