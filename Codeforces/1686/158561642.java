import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int sum = 0;
		    boolean found = true;
		    int[] arr = new int[n];
		    
		    arr[0] = sc.nextInt();
		    sum += arr[0];
		    for (int j = 1; j < n; j++){
		        arr[j] = sc.nextInt();
		        sum += arr[j];
		        if (arr[j] != arr[j-1])
		            found = false;
		    }
		    
		    for (int j = 0; j < n; j++){
		        if(arr[j] == (double)(sum - arr[j])/(n-1) || found){
		            found = true;
		            break;
		        }
		    }
		    
		    if(found)
		        System.out.println("YES");
		    else
		        System.out.println("NO");
		}
	}
}
