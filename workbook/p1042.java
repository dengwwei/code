package workbook;

import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 * p1042
 *WWWWWWWWWWWWWWWWWWWWWWLWE
 *先按11分制去数数到11的倍数，且二者分差大于二
 *再按21分制再输一遍，剩下的表示最后结果为几比几
 *输入方法可以多用输入流的方法，可以合理引入两大list
 *string类真的很重要
 *用迭代器必须引入list
 *习惯用static方法去缩短运行时间
 *链表迭代器法：https://blog.csdn.net/gudada010/article/details/114682835
 *普通法：https://blog.csdn.net/a1439775520/article/details/90722794
 */
public class p1042 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
//		Scanner input = new Scanner(System.in);
//		char[] score = {} ;
//		char ch = 0;
//		int i=0;
//		do{
//			 ch=input.next().charAt(i);
//			 score[i]=ch;
//		}while (ch=='E') ;
//		input.close();
		String str;
		StringBuilder sb = new StringBuilder();
		Scanner input = new Scanner(new BufferedInputStream(System.in));
		do {
			sb.append(input.next());
		}while(sb.indexOf("E")==-1);
		str=sb.substring(0, sb.indexOf("E")+1);
		int countw=0;
		int countl=0;
		for(int j=0;j<str.length();j++)
		{
			if(str.charAt(j)=='W')
				countw++;
			else if(str.charAt(j)=='L')
				countl++;
			if(countw-countl>=2) {
				if(countw>=11) {
					System.out.println(countw+":"+countl);
					countl=countw=0;
				}
			}
			if(countl-countw>=2) {
				if(countl>=11) {
					System.out.println(countw+":"+countl);
					countl=countw=0;
				}
			}
		}
		System.out.println(countw+":"+countl);
		System.out.println();
		System.out.println();
		countl=countw=0;
		for(int j=0;j<str.length();j++)
		{
			if(str.charAt(j)=='W')
				countw++;
			else if(str.charAt(j)=='L')
				countl++;
			if(countw-countl>=2) {
				if(countw>=21) {
					System.out.println(countw+":"+countl);
					countl=countw=0;
				}
			}
			if(countl-countw>=2) {
				if(countl>=21) {
					System.out.println(countw+":"+countl);
					countl=countw=0;
				}
			}
		}
		System.out.println(countw+":"+countl);
	}

}
