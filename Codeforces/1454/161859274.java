import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    int k = 1;
		    
		    for (int j = 1; j < n+1; j++){
		        if ((j+1)%(n+1) == 0)
		            System.out.print(1 + " ");
		        else      
		            System.out.print((j+1)%(n+1) + " ");
		    }
		    System.out.println();
		}
	}
}
