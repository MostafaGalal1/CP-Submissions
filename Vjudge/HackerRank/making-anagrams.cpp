import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] s1 = s.split("");
        s = sc.nextLine();
        String[] s2 = s.split("");
        int count = 0;
        
        for (int i = 0; i < s1.length; i++){
            for (int j = 0; j < s2.length; j++){
                if (s1[i].equals(s2[j])){
                    s2[j] = "*";
                    count++;
                    break;
                }
            }    
        }
        
    	System.out.println(s1.length + s2.length - count * 2);
	}
}
