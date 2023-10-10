import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String w = sc.next();
		int upper = 0;
		
		for (int i = 0; i < w.length(); i++){
		    if (w.charAt(i) < 97)
		        upper++;
		}
        
        String n = "";
        if(upper > w.length()/2){
            for (int i = 0; i < w.length(); i++){
                if (w.charAt(i) >= 97)
    		        n += (char)(w.charAt(i) - 32);
    		    else
    		        n += w.charAt(i);
            }
        }else{
            for (int i = 0; i < w.length(); i++){
                if (w.charAt(i) < 97)
    		        n += (char)(w.charAt(i) + 32);
    		    else
    		        n += w.charAt(i);
            }
        }
        
        System.out.println(n);
	}
}
