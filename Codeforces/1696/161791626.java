import java.util.*;
 
public class Main
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i =0; i < t; i++){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    int count = 0;
		    
		    for (int j = 0; j < n ; j++){
		        arr[j] = sc.nextInt();    
		    }
		    
		    if (arr[0] != 0)
		        count++;
		        
		    for (int j = 1; j < n ; j++){
		        if(arr[j] != 0 && arr[j - 1] == 0){
		            count++;
		        }    
		    }
		    
		    System.out.println(Math.min(count, 2));
		}
	}
}