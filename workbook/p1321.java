package workbook;

import java.util.Scanner;

public class p1321 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		String str =input.nextLine();
		input.close();
		int boy=0;
		int girl=0;
		System.out.print(str.length());
		for(int i=0;i<str.length()-2;i++)
		{
			if(str.charAt(i)=='b'||str.charAt(i+1)=='o'||str.charAt(i+2)=='y')
				boy++;
		}
		for(int i=0;i<str.length()-3;i++)
		{
			 if(str.charAt(i)=='g'||str.charAt(i+1)=='i'||str.charAt(i+2)=='r'||str.charAt(i+3)=='l')
				girl++;
		}
		System.out.println(boy);
		System.out.print(girl);
	}

}
