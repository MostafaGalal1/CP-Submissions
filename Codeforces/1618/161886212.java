import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int num = 0;
		    int[] arr = new int[7];

		    for (int j = 0; j < 7; j++){
		        arr[j] = sc.nextInt();
		    }

		    num = arr[0] + arr[1];
		    
		    for (int j = 2; j < 7; j++){
		        if (arr[j] != num || (arr[j-1] == arr[j] && arr[j] == num)){
		            num = arr[j];
		            break;
		        }
		    }
		    
		    System.out.print(arr[0] + " " + arr[1] + " " + num);
		    System.out.println();
		}
	}
}
