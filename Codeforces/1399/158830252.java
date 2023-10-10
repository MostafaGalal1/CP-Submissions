import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for(int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    boolean done = false;
		    
		    for(int j = 0; j<n; j++){
		        arr[j] = sc.nextInt();
		    }
		    
		    Arrays.sort(arr);
		    
		    for(int j = 1; j<n; j++){
		        if(arr[j] > arr[j-1] + 1){
		            System.out.println("NO");
		            done = true;
		            break;
		        }
		    }
		    
		    if(!done)
		        System.out.println("YES");
		}
	}
}
