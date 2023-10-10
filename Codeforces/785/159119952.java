import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int sum = 0;
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        map.put("Tetrahedron", 4);
        map.put("Cube", 6);
        map.put("Octahedron", 8);
        map.put("Dodecahedron", 12);
        map.put("Icosahedron", 20);
		    
		for (int i = 0 ; i < n; i++){
		    sum += map.get(sc.next());
		}
		
		System.out.println(sum);
	}
}
