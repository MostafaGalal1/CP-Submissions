import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i< t; i++){
		    int n = sc.nextInt();

		    for (int j = 0 ; j < n; j++){
		        System.out.print((int)Math.pow(2, (int)(Math.log(sc.nextInt()) / Math.log(2))) + " ");
		    }
		    System.out.println();
		}
	}
}
