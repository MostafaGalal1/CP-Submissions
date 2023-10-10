import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    boolean done = false;
		    String s = sc.next();
		    char c = sc.next().charAt(0);

    	    for (int j = 0; j < s.length(); j++){
                if (s.charAt(j) == c && j%2 == 0){
                    System.out.println("YES");
                    done = true;
                    break;
                }
    	    }
		    
		    if (!done){
		        System.out.println("NO");
		    }
		}
	}
}
