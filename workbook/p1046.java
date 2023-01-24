package workbook;
import java.util.*;
public class p1046 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Scanner input=new Scanner(System.in);
		int apple[]= new int[11];
		for(int i=0;i<apple.length-1;i++)
		{
			apple[i]=input.nextInt();
		}
		int num=input.nextInt();
		for(int i=0;i<apple.length-1;i++)
		{
			if(apple[i]<=(num+30))
			apple[10]++;
		}
		System.out.print(apple[10]);
		input.close();
	}

}
