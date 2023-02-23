package leetcode;


public class L2315 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s= "iamprogrammer";
		int count=0;
		boolean bool =true;
		for (int i = 0; i < s.length(); i++) {
			if(s.charAt(i)=='|')
				bool=!true;
			if(s.charAt(i)=='*'&&bool)
				count++;
		} 

		System.out.println(count);
	}

}
