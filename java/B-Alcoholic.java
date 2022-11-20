import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static ArrayList<String> strArray = new ArrayList<String>();
	public static void main(String[] args) {

		String a = sc.nextLine();

		String[] strlist1 = a.split(" ");

		int x = Integer.parseInt(strlist1[0]);
		int y = Integer.parseInt(strlist1[1]);

		int ans = 0;

		int i=0;
		int coun=0;

		for(i=1 ; i<=x ; i++) {

			String[] strlist2 = sc.nextLine().split(" ");

			int a1 = Integer.parseInt(strlist2[0]);
			int a2 = Integer.parseInt(strlist2[1]);

			ans = ans + ((a1*a2)/100);

			if(ans > y) {
				coun=1;
				break;
			}

		}

		if(coun == 1) {
			System.out.println(i);
		}
		else{
			System.out.println("-1");
		}

	}

}

