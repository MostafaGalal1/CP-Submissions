import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long fact  = 1;
		
		for (int i = 2; i < n; i++){
		    fact *= i;
		}
		
		System.out.println(fact * 2 / n);
	}
}
