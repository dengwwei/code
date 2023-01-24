package workbook;

import java.util.Scanner;

public class p1320 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		String str = input.nextLine();
		int len=str.length();
		String st;
		for(int i=0;i<len-1;i++)
		{
			st=input.nextLine();
			str+=st;
		}
		input.close();
		int num0=0,num1=0;
		System.out.print(len);
		if(str.charAt(0)=='1')
			System.out.print(" "+"0");
		for(int i=0;i<str.length();i++)
		{
			if(str.charAt(i)=='0') {
				num0++;
				if(num1!=0)
				{
					System.out.print(" "+num1);
					num1=0;
				}
			}
			else {
				num1++;
				if(num0!=0)
				{
					System.out.print(" "+num0);
					num0=0;
				}
			}
		}
		if(num0!=0)
			System.out.print(" "+num0);
		if(num1!=0)
			System.out.print(" "+num1);
	}

}//可读性太差了
//import java.util.*;可读性好很多
//
//public class P1320 {
//    private static boolean bool;
//
//    public static void main(String[] args) {
//        f();
//    }
//
//    public static void f() {
//        Scanner sc = new Scanner(System.in);
//        int sum = 0;
//        String string = sc.next().trim();
//        int len = string.length();
//        System.out.print(len);
//        for (int i = 0; i < len; i++) {
//            if (string.charAt(i) == '0' && !bool || string.charAt(i) == '1' && bool) {
//                sum++;
//            } else {
//                System.out.print(" " + sum);
//                sum = 1;
//                bool = !bool;
//            }
//        }
//        for (int i = 0; i < len - 1; i++) {
//            string = sc.next().trim();
//            for (int j = 0; j < len; j++) {
//                if (string.charAt(j) == '0' && !bool || string.charAt(j) == '1' && bool) {
//                    sum++;
//                } else {
//                    System.out.print(" " + sum);
//                    sum = 1;
//                    bool = !bool;
//                }
//            }
//        }
//        System.out.print(" " + sum);
//    }
//}


