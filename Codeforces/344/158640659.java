import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		int curr_num = 0;
		int next_num = 0;
		int count= 0;
		
	    for (int i = 0 ; i < n; i++){
	        next_num = sc.nextInt();
	        if (next_num != curr_num){
	            curr_num = next_num;
	            count++;
	        }
	    }
		
		System.out.println(count); 
	}
}
