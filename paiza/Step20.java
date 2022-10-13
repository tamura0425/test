package test;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static HashMap<Integer,Integer> MapBonus = new HashMap<>();
	public static void main(String[] args){
		
		//・1 行目では、受験者の人数を表す整数 N が与えられます。
        int n = sc.nextInt();
        
        //・2 行目では、1 〜 5 の各科目の重みを表す整数
        int[] m = new int[5];
        for (int i = 0; i < 5; i++) {
            m[i] = sc.nextInt();
        }
        
        //続く N 行のうち i 行目では i 番目の受験者が各科目でとった点数を表す整数
        int[][] a = new int[n][5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        
        //処理
        int max = 0;
        for (int i = 0; i < n; i++) {
            int score = 0;
            for (int j = 0; j < 5; j++) {
                score += a[i][j] * m[j];
            }
            max = Math.max(max, score);
        }

        System.out.println(max);
    }
}
