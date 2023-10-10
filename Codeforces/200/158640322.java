import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		Double v = 0D;
		
	    for (int i = 0 ; i < n; i++){
	        v += sc.nextDouble();
	    }
		
		System.out.println(v / n);  
	}
}
