import java.util.Scanner;

public class Spoj_infinity {
	
	public static void main ( String [] args){
		
		Scanner sc = new Scanner ( System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		if ( c == 0){
			System.out.println("YES");
		}
		else{
		if (b > a){
			if ( (b - a) % c == 0){
				System.out.println("YES");
			}
			else 
				System.out.println("NO");
		}
		else 
			System.out.println("NO");
	}
	}

}
