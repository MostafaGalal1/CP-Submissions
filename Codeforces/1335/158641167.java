import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int t = sc.nextInt();
		
	    for (int i = 0 ; i < t; i++){
		    System.out.println(Math.round(sc.nextDouble() / 2) - 1);    
	    }
	}
}
