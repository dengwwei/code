package leetcode;

public class L643 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		int[] nums = new int[] {1,12,-5,-6,50,3};
		int k=4;
		double sum=0.0;
		double cnt=0;
		for(int i=0,j=0;i<nums.length;i++) {
			sum+=nums[i];
			if(i-j+1==k) {
				if(sum/k-cnt>0)
					cnt=sum/k;
				sum=sum-nums[j++];
			}
		}
		System.out.println(cnt);
	}

}
