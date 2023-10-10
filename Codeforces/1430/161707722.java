import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    if (n % 3 == 0){
		        System.out.println((n/3) + " " + 0 + " " + 0);
		    } else if (n % 3 == 1){
		        if (n < 6){
		            System.out.println(-1);
		        } else {
		            System.out.println((n/3 - 2) + " " + 0 + " " + 1);
		        }
		    } else {
		        if (n < 3){
		            System.out.println(-1);
		        } else {
		            System.out.println((n/3 - 1) + " " + 1 + " " + 0);
		        }
		    }
		}
	}
}
