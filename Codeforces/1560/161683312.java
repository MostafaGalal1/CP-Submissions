import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int res = 1;

		    for (int j = 1; j < n+1; j++){
		        if (res%3 == 0)
		            res++;
		        if (res%10 == 3)
		            res++;
		        if (res%3 == 0)
		            res++;
		        res++;
		    }
		    
		    System.out.println(--res);
		}
	}
}
