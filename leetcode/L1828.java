package leetcode;

public class L1828 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[][] queries = new int[][] { { 2, 3, 1 }, { 4, 3, 1 }, { 1, 1, 2 } };
		int[][] points = new int[][] { { 1, 3 }, { 3, 3 }, { 5, 3 }, { 2, 2 } };
		int m = points.length, n = queries.length;
		int xi, yi, ri, xj, yj;
		int[] ans = new int[n];
		for (int i = 0; i < n; i++) {
			xi = queries[i][0];
			yi = queries[i][1];
			ri = queries[i][2];
			for (int j = 0; j < m; j++) {
				xj = points[j][0];
				yj = points[j][1];
				if (((int) Math.pow(xi - xj, 2) + (int) Math.pow(yi - yj, 2)) <= ri*ri)
					ans[i]++;
			}

		}
//		return ans;
		for (int i : ans) {
			System.out.println(i);
		}
		System.out.println(ans);
	}

}
