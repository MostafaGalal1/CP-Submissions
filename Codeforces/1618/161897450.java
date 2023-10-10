import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++){
		    int n = sc.nextInt();
		    long[] arr = new long[n];
		    boolean done = false;
		    
		    for (int j = 0; j < n; j++){
    		    arr[j] = sc.nextLong();
    		}
    		
    		long a = arr[0];
    		long c = arr[1];
    		long gcdo = a;
    		long gcde = c;
    		long tmp = 0;
    		long b = 0;
    		long d = 0;
    		
    		for (int j = 0; j < n-2; j+=2){
    		    b = arr[j+2];
    		    try{
    		        d = arr[j+3];
    		    } catch (Exception e){}
    		    while (b > 0 && gcdo != 1){
    		        tmp = a;
    		        a = b;
    		        b = tmp%b;
    		    }
    		    while (d > 0 && gcde != 1){
    		        tmp = c;
    		        c = d;
    		        d = tmp%d;
    		    }
    		    gcdo = a;
    		    gcde = c;
    		    if (gcdo == gcde){
    		        System.out.println(0);
    		        done = true;
    		        break;
    		    }
    		}
    		
    		if (!done){
    		    if (gcdo == gcde){
    		        System.out.println(0);
    		        done = true;
    		    } else {
    		        boolean faile = false;
    		        boolean failo = false;
            		for (int j = 1; j < n; j+=2){
            		    if (arr[j]%gcdo == 0){
            		        failo = true;
            		        break;
            		    }
            		}
        		    for (int j = 0; j < n && !done; j+=2){
            		    if (arr[j]%gcde == 0){
            		        faile = true;
            		        break;
            		    }
            		}
            		if(failo && faile){
            		    System.out.println(0);
            		} else if (failo){
            		    System.out.println(gcde);
            		} else if (faile){
            		    System.out.println(gcdo);
            		} else {
            		    System.out.println(Math.max(gcdo, gcde));    
            		}
            		done = true;
        		}
        		
        		if(!done)
    		        System.out.println(Math.max(gcdo, gcde));
    		}
		}
	}
}
