import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String[][] players = new String[n][2];
        for (int i = 0; i < n; i++) {
            String[] input = sc.nextLine().split(" ");
            players[i][0] = input[0];
            players[i][1] = input[1];
        }
        Arrays.sort(players, (a, b) -> Integer.compare(Integer.parseInt(a[0]), Integer.parseInt(b[0])));
        for (String[] player : players) {
            System.out.println(player[0] + " " + player[1]);
        }
    }
}


/*
上記の例では、Scannerクラスを使用して標準入力から値を読み込み、
配列に格納しています。また、Arrays.sort()メソッドを使用して、
背番号の昇順で選手情報を並び替えています。
最後に、選手情報を出力しています。
*/
