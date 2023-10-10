import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		System.out.println(Character.toString(s.charAt(0)).toUpperCase() + s.substring(1, s.length()));
	}
}
