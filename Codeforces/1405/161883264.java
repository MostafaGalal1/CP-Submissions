import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    long[] arr = new long[n];
		    long sum = 0;
		    long min = Long.MAX_VALUE;
		    
		    for (int j = 0; j < n; j++){
    		    arr[j] = sc.nextLong();
		    }
		    
		    for (int j = 0; j < n; j++){
		        sum += arr[j];
    		    arr[j] = sum;
    		    if (arr[j] < min){
    		        min = arr[j];
    		    }
		    }
		    
		    System.out.println(Math.abs(min));
		}
	}
}
