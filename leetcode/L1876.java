package leetcode;

public class L1876 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s = "xyzzaz";
		int count=0;
		for(int i=0;i<s.length()-2;i++) {
			if(s.charAt(i)!=s.charAt(i+1)&&s.charAt(i+1)!=s.charAt(i+2)&&s.charAt(i)!=s.charAt(i+2)) {
				count++;
			}
		}
		System.out.println(count);
	}

}
