package paiza;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        double K = sc.nextDouble();

        int total = 0;
        
        for (int i = 0; i < N; i++) {
            double x = sc.nextDouble();
            total += (int) Math.round(x * 10);
        }
    	
        //Math.roundメソッド 数値を四捨五入した値を取得
        if (total % Math.round(K * 10) == 0) {
        	long answer = total / Math.round(K * 10);
            System.out.println(answer);
        } else {
        	long answer = total / Math.round(K * 10) + 1;
            System.out.println(answer);
        }
    }
}
