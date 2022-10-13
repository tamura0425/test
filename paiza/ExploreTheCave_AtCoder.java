package test;
import java.util.ArrayList;
import java.util.Scanner;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList<Integer> intArray = new ArrayList<Integer>();
	public static void main(String[] args){

		String[] strList1 = sc.nextLine().split(" ");
		//部屋数
		int NumbeOfRooms = Integer.parseInt(strList1[0]);
		//ボーナスステージの数
		int BonusStage = Integer.parseInt(strList1[1]);
		//持ち時間
		int AllottedTime  = Integer.parseInt(strList1[2]);
		
		//消費タイムを入力
		String [] ConsumptionTime = sc.nextLine().split(" ");

		//バーナスと追加時間を入力
		int[] ArrayBonus = new int [1000000];
		
		int x=0,y=0;
		for(int i = 1; i <= BonusStage; i++ ) {
			
			String[] str = sc.nextLine().split(" ");
			//部屋番号
			x = Integer.parseInt(str[0]);
			//増加時間
			y = Integer.parseInt(str[1]);
			if((i+1)==x) {
				ArrayBonus[i+1]=y;
			}
		}
		//処理
		for(int i = 1; i < NumbeOfRooms; i++) {
			if(AllottedTime <= Integer.parseInt(ConsumptionTime[i-1])) {
				System.out.println("No");
				return;
			}
			AllottedTime = AllottedTime - Integer.parseInt(ConsumptionTime[i-1]);
			AllottedTime = AllottedTime + ArrayBonus[i+1];
		}
		System.out.println("Yes");
	}
}

