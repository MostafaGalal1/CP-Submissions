import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int s = sc.nextInt();
		
		for (int i = 0; i < s; i++){
		    if (n%10 == 0)
		        n /= 10;
		    else
		        n -= 1;
        }
        
        System.out.println(n);
	}
}
