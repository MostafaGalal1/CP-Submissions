import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    int max = 0;
		    int index = -1;
		    
		    arr[0] = sc.nextInt();
		    for (int j = 1; j < n; j++){
		        arr[j] = sc.nextInt();
		        if(arr[j] != arr[j-1]){
		            if (arr[j] > max && arr[j] > arr[j-1]){
    		            max = arr[j];
    		            index = j+1;
		            } else if (arr[j-1] > max && arr[j-1] > arr[j]){
		                max = arr[j-1];
    		            index = j;
		            }
		        }
		    }
		    
		    System.out.println(index);
		}
	}
}
