import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    
	    for (int i = 0; i < t; i++){
	        int n = sc.nextInt();
	        int even = 0;
	        int odd = 0;
	        
	        for (int j = 0; j < n; j++){
	            if (sc.nextInt()%2 != j%2){
	                if (j%2 == 0)
	                    odd++;
	                else
	                    even++;
	            }    
	        }
	        
	        if(even != odd)
	            System.out.println(-1);
	        else
	            System.out.println(even);
	    }
	}
}
