import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		
		for (int i = 0 ; i < n; i++){
		    if (sc.nextInt() - sc.nextInt() < -1)
		        count++;
		}
		
		System.out.println(count);
	}
}
