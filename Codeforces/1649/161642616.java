import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    long max = 0;
		    long sum = 0;
		    
		    for (int j = 0; j < n; j++){
		        int num = sc.nextInt();
		        sum += num;
		        if (num > max)
		            max = num;
		    }
		    
		    if (max * 2 > sum)
		        System.out.println(max * 2 - sum);
		    else if (sum == 0)
		        System.out.println(0);
		    else
		        System.out.println(1);
		}
	}
}
