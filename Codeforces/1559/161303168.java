import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		char[] f = {'B', 'R'};
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    String[] s = sc.next().split("");
		    int k = 0;
		    int xor = 0;
            
            if (n < 2){
                if (s[0].equals("?"))
                    System.out.println("B");
                else
                    System.out.println(s[0]);
            } else {
                while (s[0].equals("?") && k < n-1){
    	            if (s[k+1].equals("R") && k%2 == 0)
    	                s[0] = "B";
    	            else if (s[k+1].equals("B") && k%2 == 0)
    	                s[0] = "R";
    	            else if (s[k+1].equals("R") && k%2 == 1)
    	                s[0] = "R";
    	            else if (s[k+1].equals("B") && k%2 == 1)
    	                s[0] = "B";
    	            else
    	                k++;
    	        }
    	        
    	        if (k == n-1){
    	            for (int j = 0; j < n; j++){
    	                System.out.print(f[xor]);
    	                xor ^= 1;
    	            }
    	            System.out.println();
    	            continue;
    	        }
    		        
    		    for (int j = 1; j < n; j++){
    		        if (s[j].equals("?")){
    		            if (s[j-1].equals("R"))
    		                s[j] = "B";
    		            else if (s[j-1].equals("B"))
    		                s[j] = "R";
    		        }
    		    }
    		    
    		    for (int j = 0; j < n; j++){
	                System.out.print(s[j]);
	            }
	            System.out.println();
            }
		}
	}
}
