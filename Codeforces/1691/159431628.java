import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for (int m = 0; m < t; m++){
    		int n = sc.nextInt();
    		int odd = 0;
    		int even = 0;
    		int num = 0;
    		
    		for (int i = 0; i < n; i++){
    		    num = sc.nextInt();
    		    if (num % 2 == 0)
    		        even++;
    		    else
    		        odd++;
    		}
    		
    		System.out.println(Math.min(even, odd));    
		}
	}
}
