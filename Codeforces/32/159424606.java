import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.next().split("");
		String res = "";
		boolean added = true;
		
		for (int i = 0; i < s.length; i++){
		    if (s[i].equals(".") && added){
		        res += "0";
		        added = true;
		    } else if (s[i].equals(".")){
		        res += "1";
		        added = true;
		    } else if (s[i].equals("-") && !added){
		        res += "2";
		        added = true;
		    } else
		        added = false;
		}
		
		System.out.println(res);
	}
}
