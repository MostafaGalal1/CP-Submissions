import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();

        for (int i = 0; i < n; i++){
            if (i%2 == 0){
                for (int j = 0; j < m; j++){
                    System.out.print("#");           
                }
                System.out.println();
            }
            else{
                if(i/2%2 == 0){
                    for (int j = 0; j < m-1; j++){
                       System.out.print(".");
                    }
                    System.out.println("#");
                }
                else{
                    System.out.print("#");
                    for (int j = 1; j < m; j++){
                       System.out.print(".");
                    }
                    System.out.println();
                }
            }
        }
	}
}
