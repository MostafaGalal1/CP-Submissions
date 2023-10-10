import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		boolean done = false;
		
		if (s1.length() == s2.length()){
		    for (int i = 0 ; i < s2.length(); i++){
		        if (s1.charAt(i) != s2.charAt(s2.length() - 1 - i)){
		            System.out.println("NO");
		            done = true;
		            break;
		        }
		    }
		    if (!done)
		        System.out.println("YES");
		} else {
		    System.out.println("NO");
		}  
	}
}
