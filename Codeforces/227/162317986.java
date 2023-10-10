import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		HashMap<Integer, int[]> map = new HashMap<Integer, int[]>();
		int n = sc.nextInt();
		long vasya = 0, petya = 0;
		
		for (int i = 0; i < n; i++){
		    int num = sc.nextInt();
		    int[] arr = {i, n-1-i};
		    map.put(num, arr);
		}
		
		int m = sc.nextInt();
		
		for (int i = 0; i < m; i++){
		    int q = sc.nextInt();
		    if (map.containsKey(q)){
		        vasya += map.get(q)[0] + 1;
		        petya += map.get(q)[1] + 1;
		    }
		}
		
		System.out.println(vasya + " " + petya);
	}
}
