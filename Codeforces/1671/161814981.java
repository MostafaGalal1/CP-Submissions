import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    String[] s = sc.next().split("");
		    boolean done = false;
		    
		    if (s.length < 2 || !s[0].equals(s[1]) || !s[s.length-1].equals(s[s.length-2])){
		        System.out.println("NO");
		        done = true;
		    }
		    
		    for (int j = 1; j < s.length-1 && !done; j++){
		        if (!s[j].equals(s[j-1]) && !s[j].equals(s[j+1])){
		            System.out.println("NO");
		            done = true;
		            break;
		        }
		    }
		    
		    if (!done)
		        System.out.println("YES");
		}
	}
}
