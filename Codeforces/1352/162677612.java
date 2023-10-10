import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
    
        for (int i = 0; i < t; i++){
            int n0 = sc.nextInt();
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            
            if (n1 == 0){
                if (n2 == 0){
                    for (int j = 0; j < n0; j++){
                        System.out.print("0");
                    }
                    System.out.print("0");
                } else if (n0 == 0){
                    for (int j = 0; j < n2; j++){
                        System.out.print("1");
                    }
                    System.out.print("1");
                }
            } else {
                if (n1%2 == 0){
                    if (n2 == 0){
                        for (int j = 0; j < n1/2; j++){
                            System.out.print("01");
                        }
                        for (int j = 0; j < n0; j++){
                            System.out.print("0");
                        }
                        System.out.print("0");
                    } else if (n0 == 0){
                        for (int j = 0; j < n2; j++){
                            System.out.print("1");
                        }
                        for (int j = 0; j < n1/2; j++){
                            System.out.print("10");
                        }
                        System.out.print("1");
                    } else {
                        for (int j = 0; j < n2; j++){
                            System.out.print("1");
                        }
                        for (int j = 0; j < n1/2; j++){
                            System.out.print("10");
                        }
                        for (int j = 0; j < n0-1; j++){
                            System.out.print("0");
                        }
                        System.out.print("01");
                    }
                } else {
                    for (int j = 0; j < n2; j++){
                        System.out.print("1");
                    }
                    for (int j = 0; j < n1/2 + 1; j++){
                        System.out.print("10");
                    }    
                    for (int j = 0; j < n0; j++){
                        System.out.print("0");
                    }
                }
            }
            System.out.println();
        }
	}
}
