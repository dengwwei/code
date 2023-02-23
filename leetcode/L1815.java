package leetcode;

import java.util.Scanner;

public class L1815 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input = new Scanner(System.in);
		String[] groups=input.nextLine().split(" ");
		input.close();
		int count=0;
		for(int i=1;i<groups.length;i++) {
			if(groups[i]=="0") {
			 continue;	
			}
			else if (Integer.valueOf(groups[i])%Integer.valueOf(groups[0])==0&&Integer.valueOf(groups[i])!=0) {
				count++;
				groups[i]="0";
			}
			else {
				for(int j=1;j<groups.length;j++) {
					if(Integer.valueOf(groups[i])+Integer.valueOf(groups[i+1])>=Integer.valueOf(groups[0])) {
						count++;
						groups[i]=groups[i+1]="0";
						break;
					}
				}
			}
		}
		System.out.println(count);
	}

}
