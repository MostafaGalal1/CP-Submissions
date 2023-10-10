import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    HashMap<Long, Boolean> l = new HashMap<Long, Boolean>(); 
		    int n = sc.nextInt();
            int count = 1;
            
		    for (int j = 2; j <= Math.sqrt(n); j++){
		        long two = (long)Math.pow(j,2);
		        long three = (long)Math.pow(j,3);
		        if (Math.pow(j,2) <= n && !l.containsKey(two)){
		            count++;
		            l.put(two, true);
		        }
		        if (Math.pow(j,3) <= n && !l.containsKey(three)){
		            count++;
		            l.put(three, true);
		        }
		    }
		    
		    System.out.println(count);
    		        
		}
	}
}
