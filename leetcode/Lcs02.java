package leetcode;

import java.util.Arrays;

public class Lcs02 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] questions = new int[] {1,5,1,3,4,5,2,5,3,3,8,6};
		int len = questions.length;
		int[] vis = new int[1001] ;
		int n = len/2;
		int count=0;
		for(int i : questions) {
			vis[i]++;
		}
		Arrays.sort(vis);
		len=vis.length-1;
		while(n>0) {
			n-=vis[len];
			count++;
			len--;
		}
		System.out.println(count);
	}

}
