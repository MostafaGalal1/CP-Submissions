import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
    
        for (int i = 0; i < t; i++){
            Deque<Integer> de = new LinkedList<Integer>();
            int n = sc.nextInt();
            
            if (n < 4)
                System.out.print("-1");
            else {
                de.addFirst(2);
                de.addFirst(4);
                de.addFirst(1);
                de.addFirst(3);
                
                for (int j = 5; j <= n; j++){
                    if (j%2 == 0)
                        de.addLast(j);
                    else 
                        de.addFirst(j);
                }
            }
            
            for (int j = 1; j <= n && de.size() > 0; j++){
                System.out.print(de.removeFirst() + " ");
            }
            System.out.println();
        }
	}
}
