import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    String[] s = sc.next().split("");
		    boolean done = false;
		    
		    int r = 0;
		    int b = 0;
		    
		    for(int j = 0; j < n; j++){
		        if (s[j].equals("W")){
		            if ((r == 0 && b != 0) || (r != 0 && b == 0)){
		                System.out.println("NO");
		                done = true;
		                break;
		            } else {
		                r = 0;
		                b = 0;
		            }
		        } else {
		            if (s[j].equals("R")){
		                ++r;
		            } else {
		                ++b;  
		            }
		        }
		    }
		    
		    if (!done && ((r > 0 && b == 0) || (r == 0 && b > 0))){
		        System.out.println("NO");
		        done = true;
		    }
		    
		    if (!done)
		        System.out.println("YES");
		}
	}
}
