package leetcode;

import java.util.HashMap;

public class L2325 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String message = "vkbs bs t suepuv",key = "the quick brown fox jumps over the lazy dog";
		HashMap<Character,Character > hMap = new HashMap<>();
		char ch  = 'a',c;
		for (int i = 0; i < key.length(); i++) {
			c=key.charAt(i);
			if(c!=' '&&!hMap.containsKey(c)) {
			hMap.put(c, ch);
			ch++;
			}
		}
		System.out.println(hMap);
		String s = "a";
        for (int i = 0; i < message.length(); i++) {
			c=message.charAt(i);
//			System.out.print(hMap.getOrDefault(c,' '));
			 s+=hMap.getOrDefault(c, ' ');
		}
        System.out.println(s.substring(1));
	}

}
