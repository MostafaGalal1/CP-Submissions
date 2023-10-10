import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    List<Integer> ones = new LinkedList<Integer>();
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    int first_one = -1;
		    int count = 0;
		    
		    for (int j = 0; j < n; j++){
		        arr[j] = sc.nextInt();
		        if(arr[j] == 1)
		            ones.add(j);
		    }
		    
		    int size = ones.size();
		    for (int j = 0; j < size-1; j++){
		        count += ones.get(j+1) - ones.get(j) - 1;
		    }
		    
		    System.out.println(count);

		}
	}
}
