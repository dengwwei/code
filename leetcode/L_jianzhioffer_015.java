package leetcode;

import java.util.*;

public class L_jianzhioffer_015 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s = "cbaebabacd", p = "abc";
		LinkedList<Integer> lks= new LinkedList<>();
		int[] eng = new int[26];
		for(int i=0;i<p.length();i++) {
			eng[p.charAt(i)-97]--;
		}
		for(int i=0,j=0;i<s.length();i++) {
			eng[s.charAt(i)-97]++;
			while(eng[s.charAt(i)-97]>0) {
				eng[s.charAt(j++)-97]--;
			}
			if(i-j+1==p.length())
				lks.add(j);
		}
		System.out.println(lks);
		
	}

}
