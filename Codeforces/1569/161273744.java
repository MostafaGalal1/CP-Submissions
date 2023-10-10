import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    boolean done = false;
		    int n = sc.nextInt();
		    String s = sc.next();
		    
		    for (int j = 0; j < n-1;j++){
		        if (s.charAt(j) != s.charAt(j+1)){
		            System.out.println((j+1) + " " + (j+2));
		            done = true;
		            break;
		        }
		    }
		    if (done)
		        continue;
		        
		    System.out.println(-1 + " " + -1);
		}
	}
}
