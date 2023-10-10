import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int k = sc.nextInt();
		    int zeros = 0;
		    int ones = 0;
		    int ignore = 0;
		    boolean done = false;
		    HashMap<Integer, Boolean> l = new HashMap<Integer, Boolean>();
		    String ss =sc.next();
		    
		    String[] s = ss.split("");
		    
		    for (int j = 0; j < n; j++){
		        if (!s[j].equals("?") && !l.containsKey(j%k)){
		            l.put(j%k, true);
		            String e = s[j];
		            for (int u = j%k; u < n; u = u+k){
		                if (!s[u].equals("?") && !s[u].equals(e)){
		                    System.out.println("NO");
    		                done = true;
    		                break;
		                } else {
		                    s[u] = e;
		                }
		            }
		        }
		        if (done){
		            break;
		        }
		    }
		    
		    if (!done){
    		    for (int j = 0; j < k; j++){
    		        if (s[j].equals("0"))
    		            zeros++;
    		        else if (s[j].equals("1"))
    		            ones++;
    		        else
    		            ignore++;
    		    }
    		    
    		    if ((zeros == ones) || (Math.abs(ones - zeros) <= ignore) || (Math.abs(ignore - ones) == zeros) || (Math.abs(ignore - zeros) == ones)){
    		        System.out.println("YES");
    		    } else {
    		        System.out.println("NO");
    		    }
		    }
		}
	}
}
