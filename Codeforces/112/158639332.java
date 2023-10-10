import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		
		if (s1.compareToIgnoreCase(s2)  == 0)
		    System.out.println(0);
		else if (s1.compareToIgnoreCase(s2) > 0)
		    System.out.println(1);
		else
		    System.out.println(-1);
	}
}
