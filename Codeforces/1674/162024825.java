import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int x = sc.nextInt();
		    int y = sc.nextInt();
		    
		    if (y/x == 0 || y%x != 0)
		        System.out.println(0 + " " + 0);
		    else
		        System.out.println(1 + " " + y/x);
		}
	}
}
