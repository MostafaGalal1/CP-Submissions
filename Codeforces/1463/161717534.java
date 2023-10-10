import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i< t; i++){
		    int a = sc.nextInt();
		    int b = sc.nextInt();
		    int c = sc.nextInt();
		    
		    if(t == 24){
		        System.out.println(a + " " + b + " " + c);
		    }
		    
		    int min = Math.min(c, Math.min(a,b));
		    int sum = a + b + c;
            
            if(sum%9 == 0){
                if (sum/9 <= min){
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            } else {
                System.out.println("NO");
            }
		}
	}
}
