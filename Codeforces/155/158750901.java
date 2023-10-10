import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int n = sc.nextInt();
		long max = 0;
		long min = Long.MAX_VALUE;
		
		int count = 0;
		long num1 = sc.nextLong();
		max = num1;
		min = num1;
		
		for (int i = 0; i < n-1; i++){
		    long num2 = sc.nextLong();
		    if (num2 > max){
		        count++;
		        max = num2;
		    }
		    if (num2 < min){
		        count++;
		        min = num2;
		    }
		    num1 = num2;
		}
		
		System.out.println(count);
	}
}
