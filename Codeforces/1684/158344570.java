import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int min = 9;
		    String[] s = sc.next().split("");
            if (s.length > 2){
                for (int j = 0; j < s.length; j++){
                    if (Integer.parseInt(s[j]) < min)
                        min = Integer.parseInt(s[j]);
                }
                System.out.println(min);
            }
            else
                System.out.println(s[s.length-1]);
		}
	}
}
