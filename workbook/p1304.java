package workbook;

import java.util.Scanner;

public class p1304 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		input.close();
		int num1=0,num2=0;
		for(int i=1;i<=(n-2)/2;i++)
		{
			for(int j=2;j<2*i+2;j++)
			{
				num1=j;
				num2=2*i+2-num1;
				if(primenum(num1)&&primenum(num2)&&num1<=num2)
				{
					System.out.println(2*i+2+"="+num1+"+"+num2);
					break;
				}
			}
		}
//		for (int i = 4; i <= num; i+=2) {
//            for (int j = 2; j < num; j++) {
//                if (judgePrime(j) && judgePrime(i-j)) {
//                    System.out.println(i + "=" + j + "+" + (i-j));
//                    break;
//                }
//            }
//        }

	}

	public static boolean primenum(int num)
	{
		for(int i=2;i<num;i++)
		{
			if(num%i==0)
			{
				return false;
			}
		}
		return true;
		
	}
}
