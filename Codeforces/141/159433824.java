import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        
        String[] guest = sc.next().split("");
        String[] host = sc.next().split("");
        String[] pile = sc.next().split("");
        
        if (pile.length < guest.length || pile.length < host.length){
            System.out.println("NO");
            return;
        }
        
        Arrays.sort(guest);
        Arrays.sort(host);
        Arrays.sort(pile);
		
		String g = "";
		String p = "";
		
		for (int i = 0; i < pile.length; i++){
		    p += pile[i];
		}
		
		int k = 0;
		int l = 0;
		for (int i = 0; i < pile.length; i++){
		    if (k < guest.length && l < host.length){
		        if (guest[k].charAt(0) < host[l].charAt(0)){
    		        g += guest[k];
    		        k++;
    		    } else {
    		        g += host[l];
    		        l++;
    		    }    
		    } else if (k < guest.length){
		        g += guest[k];
		        k++;
		    } else if (l < host.length){
		        g += host[l];
    		    l++;
		    } else {
		        break;
		    }
		}

		if (p.equals(g))
		    System.out.println("YES");
		else
		    System.out.println("NO");
	}
}
