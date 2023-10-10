import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    String s = sc.next();
		    int n = s.length();
		    boolean done = false;
		    
		    if (n%2 == 0){
		        for (int j = 0; j<n/2; j++){
    		        if(s.charAt(j) != s.charAt(n/2+j)){
    		            System.out.println("NO");
    		            done = true;
    		            break;
    		        }
    		    }
		    } else {
		        System.out.println("NO");
		        done = true;
		    }
		    
		    if(!done)
		        System.out.println("YES");
		}
	}
}
