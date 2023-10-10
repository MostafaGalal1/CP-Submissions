import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int k = sc.nextInt();
		    int[] arr = new int[n];
		    int score = 0;
		    
		    for (int j = 0; j < n; j++){
    		    arr[j] = sc.nextInt();
    		}
    		
    		Arrays.sort(arr);
    		
    		for (int j = 0; j < n-k; j++){
    		    if (j < n - 2*k)
    		        score += arr[j];
    		    else
    		        score += arr[j] / arr[j+k];
    		}
    		
    		System.out.println(score);
		}
	}
}
