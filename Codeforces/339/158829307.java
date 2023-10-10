import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.nextLine().split("");
		Arrays.sort(s);
		
		for(int i = s.length/2; i < s.length-1; i++){
		    System.out.print(s[i] + "+");
		}
		System.out.println(s[s.length-1]);
	}
}
