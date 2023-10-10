import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int a = sc.nextInt();
		    int b = sc.nextInt();
		    int c = sc.nextInt();
		    int n = Math.abs(a-b) * 2;
		    
		    if (n < c || n < a || n < b){
		        System.out.println(-1);
		    } else {
		        if (c == n/2)
		            System.out.println(n/2 + c);
		        else
		            System.out.println((n/2 + c)%n);
		    }
		}
	}
}
