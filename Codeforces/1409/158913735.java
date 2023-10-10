import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int j = 0 ; j < t; j++){
		    int n = sc.nextInt();
		    int b = sc.nextInt();
		    int count = 0;
		    int diff = Math.abs(n-b);
		    
		    for (int i = 10; i > 0; i--){
		        if (diff > 0){
		            count += diff/i;
		            diff -= diff/i * i;
		        }
		    }
		    
		    System.out.println(count);
		}
	}
}
