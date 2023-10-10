import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		Scanner sc = new Scanner(System.in);
		int n1 = sc.nextInt();
		int n2 = sc.nextInt();
		int n3 = sc.nextInt();
		int sum = 0;
		
		for (int i = 1 ; i < n1+1; i++){
		    for (int j = 1 ; j < n2+1; j++){
		        for (int k = 1 ; k < n3+1; k++){
		            int no = i*j*k;
		            if (map.containsKey(no)){
		                sum += map.get(no);
		            } else {
                		int result = 0;
                        for (int o = 1; o <= Math.sqrt(no); o++){
                            if (no % o == 0) {
                                if (no / o == o)
                                    result++;
                                else
                                    result = result + 2;
                            }
                        }
                        map.put(no, result);
                        sum += result;
		            }
		        }
		    }
		}
		
		System.out.println(sum);
	}
}
