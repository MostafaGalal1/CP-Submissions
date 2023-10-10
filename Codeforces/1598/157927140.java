import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    
		Scanner sc = new Scanner(System.in);
        
        long t = sc.nextLong();
        
        for (long i = 0; i < t; i++){
            
            HashMap<Long, Long> map = new HashMap<Long, Long>();
            long n = sc.nextInt();
            long s = 0;
            long[] arr = new long[(int)n];
            long sum = 0;
            
            for (int j = 0; j < n; j++){
                arr[j] = sc.nextInt();
                sum += arr[j];
                if (map.containsKey(arr[j]))
                    map.put(arr[j], map.get(arr[j]) + 1);
                else
                    map.put(arr[j], 1L);
            }
            
            long pairs = 0;

            double nu = (double)sum*2/n;
            if (nu != (long)nu){
                System.out.println(pairs);
                continue;
            }
 
            for (int j = 0; j < n; j++){
                long num = sum*2/n - arr[j];
                
                if (map.containsKey(num)){
                    if (num == arr[j])
                        pairs += map.get(num)-1;
                    else
                        pairs += map.get(num);
                    map.put(arr[j], map.get(arr[j])-1);    
                }
            }
            
            System.out.println(pairs);
        }
	}
}
