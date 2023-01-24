package workbook;

import java.util.Scanner;

public class p1830 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		int x = input.nextInt();
		int y = input.nextInt();
		int [][][] maps = new int[n][m][2];
		for(int i=0;i<x;i++) {
			int dx_1=input.nextInt()-1;
			int dy_1=input.nextInt()-1;
			int dx_2=input.nextInt()-1;
			int dy_2=input.nextInt()-1;
			for(int j=dx_1;j<=dx_2;j++) {
				for(int k=dy_1;k<=dy_2;k++) {
					if(j>=0&&k>=0&&j<n&&k<m) {
						maps[j][k][0]++;
						maps[j][k][1]=i+1;
					}
				}
			}
		}
		for(int i=0;i<y;i++) {
			int dx=input.nextInt()-1;
			int dy=input.nextInt()-1;
			if(maps[dx][dy][0]!=0) {
				System.out.println("Y"+" "+maps[dx][dy][0]+" "+maps[dx][dy][1]);
			}
			else {
				System.out.println("N");
			}
			
		}
		input.close();
	}

}
