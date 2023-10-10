import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		int count = 0;
		
		count += n/5;
		n = n%5;
		count += n/4;
		n = n%4;
		count += n/3;
		n = n%3;
		count += n/2;
		n = n%2;
		count += n;
		
		System.out.println(count);
	}
}
