package workbook;


import java.util.Scanner;

/**
 * @author 23831
 *12847
13110
14955
13085
12340
12859
12507
12586
12696
12509
12628
 */
public class p1614 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		int[] num = new int[n];
		int sum=0;
		int minn=9999999;
		for (int i = 0; i < n; i++) {
			num[i]=input.nextInt();
		}
		for(int k= 0;k<n-m+1;k++) {
			for(int j=k;j<k+m;j++) {
				sum+=num[j];
			}
//			System.out.println(sum);
			if(sum<minn) {
				minn=sum;
			}
			sum=0;
		}
			input.close();
			System.out.print(minn);
	}
//	Scanner input = new Scanner(System.in);
//	int n = input.nextInt();
//	int m = input.nextInt();
//	int num=0,sum=0,count=0,minn=10000000;
//	for(int i=0;i<n;i++) {
//		num=input.nextInt();
//		sum+=num;
//		count++;
//		if(count==m) {
//			System.out.println(sum);
//			if(minn>sum) {
//				minn=sum;
//			}
//			sum=0;
//			count=0;
//		}
//	}
//	if(minn>sum&&sum!=0)
//		minn=sum;
//		if(n==0)
//		minn=0;
//	//System.out.print(minn);
//	input.close();
//}
}





