import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
public class Maim {

	public static void main(String[] args) {
		//ArrayList<String> array = new ArrayList<String>();
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> intList = new ArrayList<Integer>();

		int count = sc.nextInt();
		
		int num =0;
		
		for(int i= 0; i < count;i++) {
			num = sc.nextInt();
			intList.add(num);
		}
		
		
		Collections.sort(intList);
		
		for(int i : intList) {
			System.out.println(i);
		}
		
	}
}

