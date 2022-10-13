package test;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static ArrayList<Integer> intArray2 = new ArrayList<Integer>();

	static ArrayList<String> strArray = new ArrayList<String>();
	public static void main(String[] args) {
		
		String str = sc.nextLine();

		
		//人数
		int Number_of_days=Integer.parseInt(str );
		
		//ループ回数
		for(int i = 1; i <= Number_of_days ;i++) {
			String strDays = sc.nextLine();

			String[] strList1 = strDays.split(" ");
			// 開始日
			String start_date=strList1[0];
			// 終了日
			String end_date=strList1[1];	
			
			//全ての作業を配列に格納
			for(int j = Integer.parseInt(start_date); j <= Integer.parseInt(end_date);j++) {
				intArray.add(j);
			}
		}
		
		//重複を削除
		
	    List<Integer> list = new ArrayList<>();

	    for (int num : intArray) {
	        if (!list.contains(num)) {
	            list.add(num);
	        }
	    }

	    int[] newNums = new int[list.size()];
	    for (int i = 0; i < newNums.length; i++) {
	        newNums[i] = list.get(i);
	    }
		
	    //日数
	    int i = 1;
	   //連続日数
	    int counter = 0;
	    int x = 1;
		int total =0;
		int sum = 1000000;
		
		
	    for(int s : newNums) {
	    	
	    	if(s == i){ 
	    		counter = counter + 1;
	    	}
	    	
	    	
	    	else {
	    		sum = counter;
	    		
	    		if(x==1) {
	    			total=sum;
	    		}
	    		else if(total<=sum) {
	    			total=sum;
	    		}
	    		
	    		counter = 1;
	    		i=s;
	    	}
	    	i = i+1;
	    	
	    }

	    
	    
		if(total>=counter) {
			System.out.print(total);
		}
		else {
			System.out.println(counter);
		}
	}
 
}


