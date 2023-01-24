package workbook;

import java.util.Scanner;

public class p1146 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
//		Scanner input = new Scanner(System.in);
//		int m=input.nextInt();
//		int num[] = new int[1001];
//		for(int i= 0; i < m ;i++ )
//			num[i]=0;
//		int p=0;
//		int count=0;
//		for(int i=0;i<m;i++)
//		{
//			p=num[i];
//			for(int j=0 ;j<m;j++)
//				if(num[j]==0)
//					num[j]=1;
//				else if(num[i]==1)
//					num[j]=0;
//			num[i]=p;
//			for(int k=0;k<m;k++)
//				if(num[k]==1)
//					count++;
//			if(count==m)
//			{
//				for(int n:num)
//					System.out.print(n);
//				break;
//			}
//		}			
		
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int arr[] = new int[101];
		
		System.out.println(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0 ; j < n; j++) {
				if(i != j) {
					arr[j] = 1 -arr[j];
				}
				System.out.print(arr[j]);
			}
			System.out.println();
			scanner.close();
		}
	}
}
//题目要求为偶数

