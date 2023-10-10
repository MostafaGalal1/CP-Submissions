import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int t = sc.nextInt();
	    
	    for (int i = 0; i < t; i++){
	        int n = sc.nextInt();
	        int s1 = 0;
	        int s2 = 0;
	        
	        if(n%4 == 0){
                System.out.println("YES");
                for (int j = 1; j < n/2+1; j++){
                    s1 += j*2;
                    System.out.print(j*2 + " ");
                }
                for (int j = 1; j < n/2; j++){
                    s2 += j*2-1;
                    System.out.print(j*2-1 + " ");
                }
                System.out.println(s1 - s2);
	        }else
	            System.out.println("NO");
	    }
	}
}
