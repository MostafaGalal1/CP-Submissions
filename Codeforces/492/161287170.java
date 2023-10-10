import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int l = sc.nextInt();
		int[] arr = new int[n];
		int max = 0;
		
		for (int i = 0 ; i < n; i++){
		    arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		for (int i = 0; i < n-1; i++){
		    if (Math.abs(arr[i] - arr[i+1]) > max){
		        max = Math.abs(arr[i] - arr[i+1]);
		    }
		}
		
		if (max/2.0 < arr[0] || max/2.0 < (l - arr[n-1]))
		    System.out.println(Math.max(arr[0], l - arr[n-1]));
		else
		    System.out.println(max/2.0);
	}
}
