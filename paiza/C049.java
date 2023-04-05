import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 入力値の数
        int[] distances = new int[n];
        int totalDistance = 0;
        
        // 入力値を配列に格納し、距離を計算する
        for (int i = 0; i < n; i++) {
            distances[i] = sc.nextInt();
            if (i == 0) {
                totalDistance += distances[i] - 1; // 最初は1階から出発
            } else {
                totalDistance += Math.abs(distances[i] - distances[i-1]); // 階数の差分を足し合わせる
            }
        }
        
        System.out.println(totalDistance);
    }
}

/*
Scannerを使って入力値を読み込みます。
nには最初の数値が、distancesには階数の移動ログが配列として格納されます。
そして、totalDistanceはエレベーターが移動した階数の距離を保持するための変数です。

Scanner sc = new Scanner(System.in);
int n = sc.nextInt(); // 入力値の数
int[] distances = new int[n];
int totalDistance = 0;

次に、for文を使って入力値の読み込みと距離の計算を行います。
最初の場合は、エレベーターは1階から出発するため、1階を出発点として配列の最初の値から引き算をします。それ以降の場合は、前回の階数と今回の階数の差分を計算して、絶対値を取って足し合わせます。

for (int i = 0; i < n; i++) {
    distances[i] = sc.nextInt();
    if (i == 0) {
        totalDistance += distances[i] - 1; // 最初は1階から出発
    } else {
        totalDistance += Math.abs(distances[i] - distances[i-1]); // 階数の差分を足し合わせる
    }
}
最後に、計算したエレベーターが移動した階数の距離を出力します。

System.out.println(totalDistance);
以上が、Javaでエレベーターの動きのログから階数の距離を計算するプログラムの解説になります。

*/
