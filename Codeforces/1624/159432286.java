import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for (int m = 0; m < t; m++){
    		int n = sc.nextInt();
    		int max = 0;
    		int min = Integer.MAX_VALUE;
    		int num = 0;
    		
    		for (int i = 0; i < n; i++){
    		    num = sc.nextInt();
    		    if (min > num)
    		        min = num;
    		    if (max < num)
    		        max = num;
    		}
    		
    		System.out.println(max - min);    
		}
	}
}
