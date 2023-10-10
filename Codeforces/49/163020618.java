import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		String n1 = sc.next();
		String n2 = sc.next();
		
		int i = 9;
		while (true){
		    String s = Integer.toString(i);
		    if (n1.contains(s) || n2.contains(s))
		        break;
		    i--;
		}
		i++;
		
		System.out.println(Integer.toString(Integer.parseInt(n1, i) + Integer.parseInt(n2, i), i).length());
	}
}
