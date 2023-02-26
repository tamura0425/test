import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String s = sc.nextLine();
        sc.close();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (Character.getNumericValue(s.charAt(i)) == n) {
                count++;
            }
        }
        System.out.println(count);
    }
}



/*
Scannerを使って標準入力から値を受け取ります。

ScannerのnextLineメソッドを使って、
1行目と2行目をそれぞれ文字列として受け取ります。

文字列sを一文字ずつ調べて、文字がnに等しい場合には、
count変数をインクリメントします。最後に、countの値を出力
*/
