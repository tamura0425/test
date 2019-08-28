import java.util.*;
public  class Hiro{
    Scanner sc = new Scanner(System.in);
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int a = 500 + 5000;
        System.out.println("hiro");
        
        System.out.println(a);

        System.out.println("hiro");
		
		
		System.out.println(cal0());
		System.out.println(cal1());
		System.out.println(cal2());
		System.out.println(cal3());
    }
	
	public static int cal0() {
		int back = 0;
		back = 500*25000;
		
		return back;
	}
	
	public static int cal1() {
		int back = 0;
		
		back = 1000 * 25000;
		return back;
	}
	public static int cal2() {
		int back = 0;
		back = 55000 * 25000;
		return back;
	}
	public static int cal3() {
		int back = 0;
		back = 55000 * 9000;
		return back;
	}
}