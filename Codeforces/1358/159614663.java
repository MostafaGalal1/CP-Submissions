import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long t = sc.nextLong();
		
		for(int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int m = sc.nextInt();
		    System.out.println(Math.round(n*m/2.0));
		}
		
	}
}
