package workbook;
import java.util.*;
public class p1035 {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int num;
		double sum=0.0;
		num =input.nextInt();
		for(int i=1;;i++)
		{
			sum+=1.0/i;
			if(sum>num)
			{
				System.out.print(i);
				break;
			}
		}
		input.close();
	}

}
