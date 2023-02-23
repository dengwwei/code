package leetcode;

public class L2319 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] grid = new int[][] {{5,0,0,1},{0,4,1,0},{0,5,2,0},{4,0,0,2}};
		int len =grid.length;
		boolean bool=false;
		for(int i=0;i<len;i++) {
			for(int j=0;j<len;j++)
				if(i==j||(i+j)==len-1)
					if(grid[i][j]==0)
					bool=false;
				else if(grid[i][j]!=0) {
					bool=false;
				}
		}
		System.out.println(bool);
	}

}
