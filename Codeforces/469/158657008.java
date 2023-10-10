import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		Set<Integer> set = new HashSet<Integer>();

        int p = sc.nextInt();
        for (int i = 0; i < p; i++){
            set.add(sc.nextInt());    
        }
        
        int q = sc.nextInt();
		for (int i = 0; i < q; i++){
            set.add(sc.nextInt());    
        }
        
        if(set.size() < n)
            System.out.println("Oh, my keyboard!");
        else
            System.out.println("I become the guy.");
	}
}
