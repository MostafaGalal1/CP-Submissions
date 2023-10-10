import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int y = sc.nextInt();
		Set<String> set = new HashSet<String>();

		while (set.size() < 4){
		    set = new HashSet<String>();
		    y++;
		    String[] l = (Integer.toString(y)).split("");
		    for (int i = 0; i < l.length; i++){
		        set.add(l[i]);
		    }
		}
		
		System.out.println(y);
	}
}
