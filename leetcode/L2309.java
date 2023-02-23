package leetcode;

public class L2309 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		String s = "BbaA";
//		String[] str = s.split("");
		char max_value=0;
//		Arrays.sort(str);
//		for(String tString : str)
//			System.out.println(tString);
		for(int i=0;i<s.length()-1;i++) {
			for(int j=i+1;j<s.length();j++) {
				int value =s.charAt(j)-s.charAt(i);
				if(Math.abs(value)==32)
					if(s.charAt(i)-65>max_value-65) {
						max_value=s.charAt(i);
						if(s.charAt(i)-97<0)
							max_value+=32;
					}
			}
		}
		
		System.out.println(max_value);
	}

}
