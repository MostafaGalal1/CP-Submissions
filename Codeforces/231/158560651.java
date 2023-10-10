import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = 0;
		int count = 0;
		
		for (int i = 0; i < n; i++){
		    for (int j = 0; j < 3; j++){
		        if(sc.nextInt() == 1)
		            p++;
		    }
		    if (p > 1)
		        count++;
		    p = 0;
		}
		
		System.out.println(count);
	}
}
