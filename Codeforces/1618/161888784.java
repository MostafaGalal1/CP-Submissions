import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    String[] arr = new String[n-2];
		    String res = "";
		    boolean done = false;
		    
		    for (int j = 0; j < n-2; j++){
		        arr[j] = sc.next(); 
		    }
		    
		    res += arr[0].charAt(0);
		    
		    for (int j = 0; j < n-3; j++){
		        if (arr[j].charAt(1) != arr[j+1].charAt(0)){
		            res += arr[j].charAt(1);
		            res += arr[j+1].charAt(0);
		            done = true;
		        } else {
		            res += arr[j].charAt(1);
		        }
		    }
		    
		    if (done)
		        System.out.println(res + arr[n-3].charAt(1));
		    else {
		        res += arr[n-3].charAt(1);
		        System.out.println(res + arr[n-3].charAt(1));
		    }
		}
	}
}
