import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int t = sc.nextInt();
		
		String[] s = sc.next().split("");

		for (int i = 0; i < t; i++){
		    for (int j = 0; j < n-1; j++){
		        if(s[j].equals("B") && s[j+1].equals("G")){
		           s[j] = "G";
		           s[j+1] = "B";
		           j++;
		        }
		    }
		}
		
		for (int i = 0; i < n; i++) {
            System.out.print(s[i]);
        }
	}
}
