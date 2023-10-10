import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i< t; i++){
		    int n = sc.nextInt();
		    double num = n;
		    
		    if (n >= 2){
		        System.out.println(2);
		        for (int j = n-1; j>0; j--){
		            if (j == n-1){
		                System.out.println((n-1) + " " + n);
		            } else {
		                num = (j + 1 + num)/2.0;
		                System.out.println(j + " " + Math.round(num));
		            }
		        }
		    } else {
		        System.out.println(1);
		    }
		}
	}
}
