import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i =0; i < t; i++){
		    int n = sc.nextInt();
		    long z = sc.nextInt(); 
		    long[] a = new long[n];
		    long max = 0;
		    
		    for (int j = 0; j < n; j++){
		        a[j] = sc.nextLong();  
		        if ((a[j]|z) > max){
		            max = a[j]|z;
		        }
		    }
		    
		    System.out.println(max);
		}
	}
}
