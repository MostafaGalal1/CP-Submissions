import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int n = sc.nextInt();
		String love = "I love ";
		String hate = "I hate ";
		String s = "";
		int turn = 1;
		
		for (int i = 0; i < n-1; i++){
		    if (turn == 0)
		        s += love;
		    else
		        s += hate;
		    s += "that ";
		    turn ^= 1;
		} 
		
		if (turn == 0)
		    System.out.println(s + love + "it");
		else
		    System.out.println(s + hate + "it");
	}
}
