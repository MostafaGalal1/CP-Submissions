import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    boolean done = false;
		    int l = sc.nextInt();
		    int h = sc.nextInt();
		    int a = sc.nextInt();

            int res = (h + 1) / a * a - 1;
            if (res >= l)
                System.out.println(res/a + res%a);
            else
                System.out.println(h/a + h%a);
		}
	}
}
