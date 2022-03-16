package main;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	static ArrayList<String> strList = new ArrayList<String>();
	static ArrayList<Integer> IntList = new ArrayList<Integer>();
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		//標準入力変数
		
		String str1 = sc.nextLine();
		//String str2 = sc.nextLine();
		
		String[] strArray = str1.split(" ");
		
		int Number_1 = Integer.parseInt(strArray[0]);
		double Number_2 = Double.parseDouble(strArray[1]);
		
		double Number_3 = 0;
		double ans = 0;
		double ans2 = 0;

		int ans4 = 0;
		
		for(int i = 0; i < Number_1; i++) {
			String str2 = sc.nextLine();
			
			Number_3 =  Double.parseDouble(str2);
			
			ans = ans + Number_3;	
		}
		
		ans2 = ans/Number_2;
		ans4 =	(int)Math.ceil(ans2);
		
		System.out.println(ans4);
		
	}
}

