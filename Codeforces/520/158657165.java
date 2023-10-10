import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		String[] s = sc.next().split("");
		Set<String> set = new HashSet<String>();
        
        if (s.length < 26){
            System.out.println("NO");
            return;
        }
        
        for (int i = 0; i < s.length; i++){
            set.add(s[i].toLowerCase());    
        }
        
        if(set.size() < 26)
            System.out.println("NO");
        else
            System.out.println("YES");
	}
}
