import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean r = false, g = false ,b = false;
		
		int count = 0;
		int n = sc.nextInt();
		String s = sc.next();

		for (int i = 0; i < n; i++){
		    if ((r && s.charAt(i) == 'R') || (g && s.charAt(i) == 'G') || (b && s.charAt(i) == 'B'))
		        count++;
		    r = false;
		    b = false;
		    g = false;
		    if (s.charAt(i) == 'R')
		        r = true;
		    else if (s.charAt(i) == 'G')
		        g = true;
		    else
		        b = true;
		}
		
		System.out.println(count);
	}
}
