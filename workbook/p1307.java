package workbook;

import java.util.Scanner;

public class p1307 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input	= new Scanner(System.in);
		int n=input.nextInt();
		String ch = String.valueOf(n);
		input.close();
		int len = ch.length();
		//System.out.print(ch.length());
		for(int i=0;i<len;i++) {
		if(ch.charAt(0)=='-')
		{
			System.out.print("-");
			ch=ch.substring(1, ch.length());
		}
		if(ch.charAt(len-1-i)=='0'&&ch.length()>1)
			ch=ch.substring(0, ch.length()-1);
		}
		StringBuffer buffer=new StringBuffer(ch);
		buffer.reverse();
		System.out.print(buffer);
		}
}
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//public class p1307 {
//    public static void main(String[] args)throws IOException {
//        BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
//        StringBuffer b = new StringBuffer(s.readLine().trim());
//        b.reverse();    //字符串反转，反转后，如果数字前面有“0”，会自动去掉。
//        if (b.charAt(b.length()-1)=='-'){
//            b.delete(b.length()-1,b.length());//反转之后，‘-’跑到最后面了，所以要删除掉。
//            b.insert(0,'-');//如果有‘-’，在开头加上
//        }
//        System.out.println(Integer.parseInt(b.toString()));
//    }
//}

