package workbook;

import java.util.Scanner;

public class p1319 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		String str = input.nextLine();
        String strtr[] = str.split(" ");
//        for(String iString : strtr)
//        	System.out.print(iString);
		input.close();
		int m;
		int count=0;
		for(int i=0;i<strtr.length-1;i++)
		{
			m=Integer.parseInt(strtr[i+1]);
			if(i%2==0) {
				for(int j=0;j<m;j++) {
					System.out.print("0");
					count++;
					if(count==n) {
						count=0;
						System.out.println();
					}
				}
			}
			else {
				for(int j=0;j<m;j++) {
					System.out.print("1");
					count++;
					if(count==n) {
						count=0;
						System.out.println();
					}
				}
			}
			
		}
	}

}
