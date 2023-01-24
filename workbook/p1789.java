package workbook;

import java.util.Scanner;

/**
 * @author 23831 mapps 地图 Torches 火把的位置 照亮范围为横竖一 ，5+5-1 fluorite 萤石的位置 5*5 自己为中心
 *
 */

public class p1789 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		int k = input.nextInt();
		int dx = 0, dy = 0;
		int[][] maps = new int[n][n];
		int[][] Torches = new int[][] { { -2, 0 }, { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -2 }, { 0, -1 }, { 0, 1 },
				{ 0, 2 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 2, 0 }, { 0, 0 } };
		for (int i = 0; i < m; i++) {
			dx = input.nextInt()-1;
			dy = input.nextInt()-1;
			for (int j = 0; j < 13; j++) {
				int d_x = dx+Torches[j][0];
				int d_y = dy+Torches[j][1];
				if (d_x >= 0 && d_y >= 0 && d_x < n && d_y < n)
					maps[d_x][d_y] = 1;
			}
		}
		for (int i = 0; i < k; i++) {
			dx = input.nextInt()-1;
			dy = input.nextInt()-1;
			for (int j = dx - 2; j <= dx + 2; j++) {
				for (int k1 = dy - 2; k1 <= dy + 2; k1++) {
					if (j >= 0 && k1 >= 0 && j < n && k1 < n)
						maps[j][k1] = 1;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maps[i][j] == 0)
					count++;
			}
		}
		input.close();
		System.out.print(count);

	}

}
