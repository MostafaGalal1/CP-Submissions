import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    String s = sc.next();
		    int count = 0;
		    char[][] arr = new char[n][n];
		    
		    for (int k = 0; k < n; k++){
		        if (s.charAt(k) == '2')
		            count++;
		    }
		    
		    if (count == 1 || count == 2){
		        System.out.println("NO");
		        continue;
		    }
		    
		    for (int k = 0; k < n; k++){
		        boolean first = true;
    		    for (int j = 0; j < n; j++){
    		        if (k != j){
        		        if (k > j){
        		            if (arr[j][k] == '+') 
        		                arr[k][j] = '-';
        		            else if (arr[j][k] == '-') 
        		                arr[k][j] = '+';
        		            else
        		                arr[k][j] = arr[j][k];
        		        } else if (s.charAt(k) == s.charAt(j)){
        		            if (s.charAt(k) == '1'){
        		                arr[k][j] = '=';
        		            }
        		            else if (s.charAt(k) == '2'){
        		                if (first){
        		                    arr[k][j] = '+';
        		                    first = false;
        		                } else
        		                    arr[k][j] = '-';
        		            }
        		        } else if (s.charAt(k) != s.charAt(j)){
        		            if (s.charAt(k) == '1'){
        		                arr[k][j] = '+';
        		            }
        		            else if (s.charAt(k) == '2'){
        		                arr[k][j] = '-';
        		            }
        		        }
    		        } else {
    		            arr[k][j] = 'X';
    		        }
    		    }
		    }
            
            System.out.println("YES");
            
		    for (int k = 0; k < n; k++){
    		    for (int j = 0; j < n; j++){
    		        System.out.print(arr[k][j]);
    		    }
    		    System.out.println();
		    }
		}
	}
}
