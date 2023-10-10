import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Set<String> set = new HashSet<String>();
		String[] s = sc.next().split("");
		
		for (int i = 0; i < s.length; i++){
		    set.add(s[i]);
		}
		
		if (set.size()%2 == 1)
		    System.out.println("IGNORE HIM!");
		else
		    System.out.println("CHAT WITH HER!");
	}
}
