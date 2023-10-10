import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		Set<Long> set = new HashSet<Long>();
		
		for (int i = 0; i < 4; i++){
		    set.add(sc.nextLong());
		}
		
		System.out.println(4 - set.size());
	}
}
