import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt()-1;
		long r = 1;
		
		for(int i = 2*n; i > 0; i--){
		    if (i > n)
		        r *= i;
		    else
		        r /= i;
		}
		
		System.out.println(r);
	}
}
