import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t ; i++){
		    int n = sc.nextInt();
		    int num = 0;
		    
		    if (n%2 == 1){
		        System.out.println(-1);
		    } else {
		        num = n/2;
		        System.out.println(num + " " + num + " " + 0);
		    }
		}
	}
}
