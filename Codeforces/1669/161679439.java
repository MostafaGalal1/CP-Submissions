import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    boolean done = false;
		    
		    for (int j = 0; j < n; j++){
		        arr[j] = sc.nextInt();
		    }
		    
		    int evenp = arr[0] % 2;
		    int oddp = arr[1] % 2;
		    
		    for(int j = 2; j < n; j++){
		        if((j%2 == 0 && evenp != arr[j]%2) || (j%2 == 1 && oddp != arr[j]%2)){
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
