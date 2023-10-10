import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    String s = sc.next();
		    System.out.println((Integer.parseInt(s)%10 - 1) * 10 + s.length()*(s.length()+1)/2);
		}
	}
}
