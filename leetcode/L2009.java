package leetcode;

import java.util.Arrays;
import java.util.HashSet;

public class L2009 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] nums=new int[] {1,10,100,1000};
		HashSet<Integer> hs = new HashSet<Integer>();
		for(int i:nums) {
			hs.add(i);
		}
		int len=hs.size();
		int[] temp=new int[len];
		int x=0;
		for(int i:hs)
			temp[x++]=i;
		Arrays.sort(temp);
		int count=0;
		for(int i=0;i<len-1;i++) {
			if(temp[i+1]-temp[i]!=1)
				count++;
		}
		x=nums.length-len;
		if(x>0&&count!=0)
			count=Math.min(x, count);
		else if(x>0&&count==0){
			count=x;
		}
		else if(x==0)
		System.out.println(count);
		
	}

}
