import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int[][] arr = new int[n][n];
		    
		    for(int j = 0; j < n; j++){
		        String[] s = sc.next().split("");
		        for(int k = 0; k < n; k++){
		            if (!((j == 0 && k == 0) || (j == n-1 && k == n-1)))
		                arr[j][k] = Integer.parseInt(s[k]);
		        }    
		    }
		    
		    if (arr[0][1] == arr[1][0] && arr[n-1][n-2] == arr[n-2][n-1] && arr[0][1] == arr[n-1][n-2]){
		        System.out.println(2);
		        System.out.println(1 + " " + 2);
		        System.out.println(2 + " " + 1);
		    } else if (arr[0][1] == arr[1][0] && arr[n-1][n-2] == arr[n-2][n-1]){
		        System.out.println(0);
		    } else if (arr[0][1] == arr[1][0]){
		        System.out.println(1);
		        if(arr[n-1][n-2] == arr[0][1]){
		            System.out.println(n + " " + (n-1));
		        } else {
		            System.out.println((n-1) + " " + n);
		        }
		    } else if (arr[n-1][n-2] == arr[n-2][n-1]){
		        System.out.println(1);
		        if(arr[0][1] == arr[n-1][n-2]){
		            System.out.println(1 + " " + 2);
		        } else {
		            System.out.println(2 + " " + 1);
		        }
		    } else {
		        System.out.println(2);
		        if (arr[0][1] == arr[n-1][n-2]){
		            System.out.println(2 + " " + 1);
		            System.out.println(n + " " + (n-1));
		        } else {
		            System.out.println(1 + " " + 2);
		            System.out.println(n + " " + (n-1));
		        }
		    }
		    
		}
	}
}
