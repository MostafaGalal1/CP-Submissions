import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		    int n = sc.nextInt();
		    boolean done = false;
		    
		    for (int j = 0; j < n; j++){
		        int num = sc.nextInt();
		        if (!map.containsKey(num)){
		            map.put(num, 1);
		        } else {
		            map.put(num, map.get(num) + 1);
		            if (!done && map.get(num) == 3){
		                System.out.println(num);
		                done = true;
		            }
		        }
		    }
		    
		    if(!done)
		        System.out.println("-1");
		}
	}
}
