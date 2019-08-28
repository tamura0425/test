import java.util.*;

public class Paiza {
    public static void main(String[] args) throws Exception {
        // Your code here!
		Scanner sc = new Scanner(System.in);
		int s,a,b,c,d;
		
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		d = sc.nextInt();
		
		s =  (a * d) - (b * c) ;
		
		int ans = -1 * (s / 2);
		
		System.out.println(ans);
    }
}
