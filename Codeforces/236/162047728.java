import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		
		if(n < 3){
		    System.out.println(n);
		    return;
		}
		
		if(n%2 == 1){
		    System.out.println(n*(n-1)*(n-2));
		    return;
		}
		
		long gcd1 = Math.min(n, n-3);
        while (gcd1 > 0) {
            if (n % gcd1 == 0 && (n-3) % gcd1 == 0)
                break;
            gcd1--;
        }
        
        long gcd2 = Math.min(n, n-2);
        while (gcd2 > 0){
            if (n % gcd2 == 0 && (n-2) % gcd2 == 0)
                break;
            gcd2--;
        }
        
        long n1 = n * (n-1) * (n-3) / gcd1;
        long n2 = n * (n-1) * (n-2) / gcd2;
        long n3 = (n-1) * (n-2) * (n-3);

		System.out.println(Math.max(Math.max(n1, n2), n3));
	}
}
