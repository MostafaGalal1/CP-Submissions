import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    HashMap<String, Integer> map = new HashMap<String, Integer>();
		    List<String> letters = new LinkedList<String>();
		    String[] s = sc.next().split("");
		    int count = 0;
		    int unique = 0;
		    
		    for (int j = 0; j < s.length; j++){
		        if (!map.containsKey(s[j])){
		            letters.add(s[j]);
		            map.put(s[j], 1);
		        } else {
		            map.put(s[j], map.get(s[j]) + 1);
		        }
		    }
		    
		    for (int j = 0; j < letters.size(); j++){
		        if (map.get(letters.get(j)) > 1){
		            count++;
		        } else {
		            unique++;
		        }
		    }
		    
		    System.out.println(count + unique / 2);
		}
	}
}
