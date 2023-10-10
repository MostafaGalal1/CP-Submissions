import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for (int m = 0; m < t; m++){
    		String[] s = sc.next().split("");
    		String res = "";
    		
    		for (int i = 0; i < s.length; i+=2){
    		    res += s[i];
    		}
    		
    		System.out.println(res + s[s.length-1]);    
		}
	}
}
