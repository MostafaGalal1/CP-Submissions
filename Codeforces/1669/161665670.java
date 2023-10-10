import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int num = sc.nextInt();
		    
		    if(num >= 1900)
		        System.out.println("Division 1");
		    else if(num >= 1600)
		        System.out.println("Division 2");
		    else if(num >= 1400)
		        System.out.println("Division 3");
		    else
		        System.out.println("Division 4");
		}
	}
}
