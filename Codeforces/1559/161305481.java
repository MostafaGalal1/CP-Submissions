import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int k = 1;
		    boolean done = false;
		    
            for (int j = 0; j < n; j++){
                if (sc.nextInt() == 1 && !done){
                    done = true;
                    System.out.print((n+1) + " ");
                    System.out.print((k++) + " ");
                } else {
                    System.out.print((k++) + " ");
                }
            }
            
            if (!done){
                System.out.print((n+1) + " ");
            }
            
            System.out.println();
		}
	}
}
