import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    String n = "";
	    n = sc.next();
		String[] n1 = n.split("");
		n = sc.next();
		String[] n2 = n.split("");
		String res = "";
		
		for (int i = 0; i < n1.length; i++){
		    res += Integer.toString(Integer.parseInt(n1[i]) ^ Integer.parseInt(n2[i]));
		}

		System.out.println(res);
	}
}
