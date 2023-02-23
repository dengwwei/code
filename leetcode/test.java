package leetcode;

import java.util.*;

public class test {

	static int[] d_x={0,1,0,-1};
    static int[] d_y={1,0,-1,0};
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
//		List<List<Integer>> edges;
//		edges = new ArrayList<List<Integer>>();
//		int[][] relation = new int[][] {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};
//		for (int i = 0; i < 5; i++) {
//            edges.add(new ArrayList<Integer>());
//        }
//        for (int[] edge : relation) {
//            int src = edge[0], dst = edge[1];
//            edges.get(src).add(dst);
//        }
//        System.out.println(edges);
//        System.out.println(edges.get(0));
//		int[][] num = new int[3][4];
//		System.out.println(num.length);
//		int[][] grid = new int[][] {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
//		int count=0;
//        int leng = grid.length;
//        int wide = grid[0].length;
//        for(int i=0;i<leng;i++){
//            for(int j=0;j<wide;j++)
//                if(grid[i][j]==1)
//                    count+=dfs(grid,i,j,leng,wide);
//        }
//        System.out.println(count);
//		int[] nums=new int[] {1,1,1,4,-1,2,1,-5,4};
//		int pre = 0, maxAns = nums[0];
//        for (int x : nums) {
//            pre = Math.max(pre + x, x);
//            maxAns = Math.max(maxAns, pre);
//        }
//		int[] nums1 = new int[] {1,2,3,0,0,0};
//		int[] nums2 = new int[] {2,5,6};
//		Arrays.sort(nums1);
//		nums1 = Arrays.copyOfRange(nums1, 3, nums1.length);
//		for(int i:nums1)
//		System.out.println(i);
//		int[][] mat = new int[][] {{1,2},{3,4}};
//		int r=1,c=4;
//		int s=r*c;
//        if(s>mat.length*mat[0].length)
//             System.out.println(Arrays.toString(mat));
//        int[][] num = new int[r][c];
//        int x=0,y=0;
//        for(int i=0;i<r;i++,y++)
//            for(int j=0;j<c;j++,x++)
//                num[i][j]=mat[x][y];
//        System.out.println(Arrays.toString(num));
//		String[] operations = new String[] {"--X","X++","X++"};
//		int x=0;
//        for(String str : operations){
//        	if(str=="X++"||str=="++X")
//                x++;
//            else
//                x--;
//        }
//        System.out.println(x);
//		String ransomNote="aa",  magazine="aab";
//		char[] ch_1 = ransomNote.toCharArray();
//        char[] ch_2 = magazine.toCharArray();
//        Map<Character,Integer> map=new HashMap<>();
//        for(char c:ch_2){
//            map.put(c,map.getOrDefault(c,0)+1);
//        }
//        for(char c:ch_1){
//            if(map.containsKey(c)) {
//                if(map.get(c)>0)
//                map.put(c,map.get(c)-1);
//            }else
//                System.out.println( false);
//        }
//        System.out.println(true);
//		String s= "()[]{}";
//		int len=s.length();
//		 for(int i=0;i<len;i++){
//	            int l=s.length();
//	            s=s.replace("()","");
//	            s=s.replace("{}","");
//	            s=s.replace("[]","");
//	            if(s.length()==l){System.out.println(l==0); break;}
//	        }
		int[] nums = new int[] {-1,0,3,5,9,12};
		int target = 9;
		 int left = 0, right = nums.length - 1;
	        while (left <= right) {
	            int mid = (right - left) / 2 + left;
	            int num = nums[mid];
	            if (num == target) {
	                System.out.println( mid);
	                break;
	            } else if (num > target) {
	                right = mid - 1;
	            } else {
	                left = mid + 1;
	            }
	        }
	        System.out.println();
	}
//	public static int  dfs(int[][] g , int dx,int dy,int leng,int wide){
//        if(dx>=leng||dx<0||dy>=wide||dy<0||g[dx][dy]==0)
//            return 1;
//        if(g[dx][dy]==2)
//            return 0;
//        g[dx][dy]=2;
//        int step=0;
//        for(int i=0;i<4;i++){
//            int x=dx+d_x[i];
//            int y=dy+d_y[i];
//            step+=dfs(g,x,y,leng,wide);
//        }
//        return step;
//    }

}
