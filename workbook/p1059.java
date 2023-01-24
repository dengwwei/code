package workbook;

import java.util.*;

public class p1059 {

	public static void main(String[] args) {
		//int stu[]=new int [100];
		TreeSet<Integer> treeSet =new TreeSet<>();
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
		for(int i=0;i<n;i++)
		{
			//stu[i]=(int)(Math.random()*(1001-1));
			//System.out.print(stu[i]);
			treeSet.add((int)(Math.random()*(1001-1)));
		}
		System.out.println(treeSet.size());
		for(Object xObject : treeSet)
		{
			System.out.print(xObject+" ");
		}
		/*Arrays.sort(stu);
		LinkedHashSet<Object> tempHashSet = new LinkedHashSet<>();
		for(int i=0;i<n;i++)
		{
			tempHashSet.add(stu[i]);
		}
		System.out.print(tempHashSet.toString());*/
			input.close();
	}

}
