import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int res = sc.nextInt();
		    
		    for (int j = 1; j < n; j++){
		        res &= sc.nextInt();
		    }
		    
		    System.out.println(res);
		}
	}
}
