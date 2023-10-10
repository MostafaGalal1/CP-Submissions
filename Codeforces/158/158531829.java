import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int k = sc.nextInt();
		int score = 0;
		int count = 0;
		int[] arr = new int[n];
		
		for (int i = 0; i < n; i++){
		    arr[i] = sc.nextInt();
		}
		
		score = arr[k-1];
		
		if (score == 0){
		    for(int j = 0; j < k-1; j++){
                if (arr[j] > 0){
                    count++;
                }
                else
                    break;
            }
		    System.out.println(count);
		}
		else{
		    count = k;
		    for(int j = k; j < arr.length; j++){
                if (arr[j] == score){
                    count++;
                }
                else
                    break;
            }
            System.out.println(count);
		}
	}
}
