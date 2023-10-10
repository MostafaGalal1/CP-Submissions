import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int[] arr = new int[3];
            arr[0] = sc.nextInt();
            arr[1] = sc.nextInt();
            arr[2] = sc.nextInt();
            
		    for (int j = 0; j < 3; j++){
		        int num = Math.max(arr[(j+1)%3], arr[(j+2)%3]);
		        System.out.print(Math.max(num - arr[j] + 1, 0));
		        System.out.print(" ");
		    }
		    System.out.println();
		}
	}
}
