import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int max = 0;
		int sum = 0;
		int num = 0;
		
		for (int i = 0; i < n; i++){
		    num = sc.nextInt();
		    sum += num;
		    if (max < num)
		        max = num;
		}
		
		System.out.println(max * n - sum);    
	}
}
