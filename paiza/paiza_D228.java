package paiza;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	static ArrayList<String> strList = new ArrayList<String>();
	static HashMap<Integer,Integer> MapBonus = new HashMap<>();
	public static void main(String[] args){
		
        Scanner sc = new Scanner(System.in);

        // 日没の時刻を取得
        int sunsetHour = sc.nextInt();
        int sunsetMinute = sc.nextInt();

        // 現在時刻を取得
        int currentHour = sc.nextInt();
        int currentMinute = sc.nextInt();

        // 日没と現在時刻を分単位で計算
        int sunsetTime = sunsetHour * 60 + sunsetMinute;
        int currentTime = currentHour * 60 + currentMinute;

        // 現在がクリスマスであるか判定
        if (currentTime >= sunsetTime) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        // 改行を出力
        System.out.println();
    }
}
