import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int k = sc.nextInt();
		    int[] arr = new int[n];
		    int[] prefix = new int[n];
		    int sum = 0;
		    
		    for (int j = 0 ; j < n; j++){
		        arr[j] = sc.nextInt();
		        sum += arr[j];
		        prefix[j] = sum;
		    }
		    
		    if (k > 1){
		        int count = 0;
		        for (int j = 1; j < n-1; j++){
    		        if (arr[j] > arr[j-1] + arr[j+1]){
    		            count++;
    		            j++;
    		        }
    		    }
    		    System.out.println(count);
		    } else {
		        if(n%2 == 0){
		            System.out.println(n/2 - 1);
		        } else {
		            System.out.println(n/2);
		        }
		    }
		}
	}
}
