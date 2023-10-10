import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean done = false;
		int n = sc.nextInt();
		int[] arr = new int[n];
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for (int i = 0; i < n; i++){
		    arr[i] = sc.nextInt()-1;
		}
		
		for (int i = 0; i< n; i++){
		    map.put(arr[i], arr[arr[i]]);
		}
		
		for (int i = 0; i< n; i++){
		    if (arr[i] == map.get(map.get(map.get(arr[i]))) && arr[i] != map.get(map.get(arr[i]))){
		        System.out.println("YES");
		        done = true;
		        break;
		    }
		}
		
		if (!done)
		    System.out.println("NO");
	}
}
