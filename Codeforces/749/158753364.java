import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		
	    int num = sc.nextInt();
	    int tw = 0;
	    int th = 0;
        
        if (num%2 == 0){
            tw += num/2;
        } else {
            tw += num/2 - 1;
            num %= 2;
            num += 2;
            th += num/3;
        }

	    System.out.println(tw + th);
	    
	    for (int i = 0; i < tw; i++){
            System.out.print("2 ");
        }
        for (int i = 0; i < th; i++){
            System.out.print("3 ");
        }
	}
}
