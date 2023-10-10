import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String w = "";
		int pos = 0;
		boolean found = false;
		
		for (int i = 0; i < 25; i++){
    		w += sc.next();
		    if (w.charAt(i) == '1' && !found){
		        pos = i;
		        found = true;
		    }
		}

        System.out.println(Math.abs(pos/5 - 2)  + Math.abs(pos%5 - 2));
	}
}
