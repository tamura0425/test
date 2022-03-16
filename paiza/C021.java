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
		String strNum = sc.nextLine();
		
		int Number_of_times = Integer.parseInt(strNum);
		
		String[] strArray = str1.split(" ");
		
		int xc = Integer.parseInt(strArray[0]);
		int yc = Integer.parseInt(strArray[1]);
		int r_1 = Integer.parseInt(strArray[2]);
		int r_2 = Integer.parseInt(strArray[3]);
		
		int r_1_Squared = r_1 * r_1;
		int r_2_Squared = r_2 * r_2;
		
		double x_Squared = 0;
		double y_Squared = 0;
		
	    double bottom = 0;   // 底
	    double index = 2;    // 指数
		
		
		for(int i = 0; i < Number_of_times; i++) {
			String str2 = sc.nextLine();
			String[] strArray2 = str2.split(" ");
			
			int xn = Integer.parseInt(strArray2[0]);
			int yn = Integer.parseInt(strArray2[1]);
			
			x_Squared = (xn-xc);
			y_Squared = (yn-yc);
			
			double result1 = Math.pow(x_Squared, index);
			double result2 = Math.pow(y_Squared, index);
			
			int ans1 = (int)result1;
			int ans2 = (int)result2;
		
			int result_ans = ans1 + ans2;
			
			if(r_1_Squared <= result_ans && result_ans <= r_2_Squared) {
				System.out.println("yes");
			}
			else {
				System.out.println("no");
			}
			strArray2 = new String[2];
		}

	}
}

