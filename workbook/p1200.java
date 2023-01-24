package workbook;

import java.util.Scanner;

public class p1200 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		String m = input.next();
		String n = input.next();
		int pm=1,pn=1;
		for(int i=0;i<6;i++)
		{
			pm*=(m.charAt(i)-64);
			pn*=(n.charAt(i)-64);		
		}
		if(pm%47==pn%47)
			System.out.print("GO");
		else 
			System.out.print("STAY");
		input.close();
 	}

}
/*Scanner sc =new Scanner(System.in);
String a = sc.nextLine();
String b = sc.nextLine();
char [] s1 = a.toCharArray();
char [] s2 = b.toCharArray();
int sum1 = 1,sum2=1;
int [] num1 = new int [s1.length];
int [] num2 = new int [s2.length];
for (int i = 0; i < num2.length; i++) {
	
	num2[i]=s2[i]-'A'+1;
	sum2*=num2[i];
}
for (int i = 0; i < num1.length; i++) {
	num1[i]=s1[i]-'A'+1;
	sum1*=num1[i];
}
if(sum1%47==sum2%47){
	System.out.println("GO");
}
else{
	System.out.println("STAY");
}
}

}*/

