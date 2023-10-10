import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int m = 0 ; m < t; m++){
		    int n = sc.nextInt();
		    sc.nextLine();
		    String[] arr = sc.nextLine().split(" ");
		    
		    if(!arr[0].equals(arr[1]) && arr[1].equals(arr[2])){
		        System.out.println(1);
		        continue;
		    }
		    
    		for (int i = 0 ; i < n-1; i++){
    		    if (!arr[i].equals(arr[i+1])){
    		        System.out.println(i+2);
    		        break;
    		    }
    		}
		}
	}
}
