import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int num = sc.nextInt();
		    String s = "";
		    boolean done = false;
		    
		    for (int j = 0 ; j < num ; j++){
		        s += sc.next();
		    }
		    
		    String[] sl = s.split("");
		    Arrays.sort(sl);
		    
		    int j = 0;
		    int n = sl.length;
		    int index = 0;
		    
		    for (j = 0 ; j < n-1 ; j++){
		        if(!sl[j].equals(sl[j+1])){
		            index = j+1;
		            if ((j+1)%num != 0){
		                System.out.println("NO");
		                done = true;
		                break;
		            }
		        }
		    }
		    
		    if (!done && (n-index)%num != 0){
                System.out.println("NO");
                done = true;
            }
		    
		    if (!done)
		        System.out.println("YES");
		}
	}
}
