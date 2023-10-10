import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    
		Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        for (int i = 0; i < t; i++){
            boolean end = false;
            int n = sc.nextInt();
            int[][] arr = new int[2][n];
            
            String str = sc.next();
            String[] l = str.split("");
            
            for (int j = 0; j < n; j++){
                arr[0][j] = Integer.parseInt(l[j]);
            }
            
            str = sc.next();
            l = str.split("");
            
            for (int j = 0; j < n; j++){
                arr[1][j] = Integer.parseInt(l[j]);
                if(arr[0][j] == 1 && arr[1][j] == 1){
                    System.out.println("NO");
                    end = true;
                    break;
                }
            }
            
            if(end)
                continue;
                
            System.out.println("YES");
        }
	}
}
