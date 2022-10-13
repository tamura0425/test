package test;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;


public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static HashMap<Integer,Integer> MapBonus = new HashMap<>();
	public static void main(String[] args){
		
		//・1 行目では、受験者の人数を表す整数 N が与えられます。
        String[] Arraystr = sc.nextLine().split(" ");
        int n = Integer.parseInt(Arraystr[0]);
        int k = Integer.parseInt(Arraystr[1]);
        int m = Integer.parseInt(Arraystr[2]);
        
        int inpout=0;
//        int[] ArraysInt = new int[n];
        for (int i = 0; i < n; i++) {
        	inpout = sc.nextInt();
        	intArray.add(inpout);
        }
        //降順並び替え
        Collections.sort(intArray, Collections.reverseOrder());
        
        
        int count = 0;
        int answer=0;
        for(int a :intArray) {
          if(k <= a) {
        	  count=count+1;
          }
          
          answer= count-m;
        }
        if(answer<=0) {
        	System.out.println(0);
        }
        else {
        	System.out.println(answer);
		}

    }
}
