import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int[] arr = new int[31];
		    int u = sc.nextInt();
		    int res = 0;
		    boolean zero = false;
		    
		    for (int j = 0; j < n; j++){
		        int nu = sc.nextInt();
		        if (nu == 0 && n == 1)
		            zero = true;
		        if (j == 0)
		            res = nu;
		        else
		            res = res & nu;
		        String num = Integer.toBinaryString(nu);
                int size = num.length();
		        for(int k = 0; k < size; k++){
		            if (num.charAt(k) == '1')
		                arr[size-1-k]++;
		        }
		    }
		    
		    for (int j = 30; j >= 0; j--){
		        if (u >= n-arr[j] && n-arr[j] > 0){
		            res += Math.pow(2, j);
		            u -= n-arr[j];
		        }
		        if (u == 0)
		            break;
		    }
		    
		    System.out.println(res);
		}
	}
}
