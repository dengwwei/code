package leetcode;

import java.util.*;

public class L219 {

	public static void main(String[] args) {
//		 TODO 自动生成的方法存根
		int[] nums=new int[] {1,2,3,1};
		int k=3;
//		boolean bool=false;
//        for(int i=0;i<nums.length-k;i++){
//            for(int j=i+1;j<nums.length&&j-i<=k;j++){
//                if(nums[i]==nums[j])
//                    bool=true;
//            }
//        }
//        System.out.println(bool);
//		大量数据就超时
		
//		 Map<Integer, Integer> map = new HashMap<Integer, Integer>();
//	        int length = nums.length;
//	        for (int i = 0; i < length; i++) {
//	            int num = nums[i];
//	            if (map.containsKey(num) && i - map.get(num) <= k) {
//	                ;
//	            }
//	            map.put(num, i);
//	        }
//		遍历所有数据，利用哈希表，最开始无数据，第一个数据进去以后，往后的数据向前比对，巧妙避免反复赋值。
		HashSet<Integer> set = new HashSet<>();
		for(int i=0;i<nums.length;i++) {
			if(i>k) {
				set.remove(i-k-1);//删除的是值不是索引
				
			}
			if(!set.add(nums[i]))
				System.out.println("true");
			
		}
		
	        
	    }

}
