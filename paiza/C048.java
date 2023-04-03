import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // コーヒーの価格と割引率をユーザーに入力してもらう
        int price = scanner.nextInt();
        int discountRate = scanner.nextInt();

        // お買い上げの価格を累積するための変数
        int totalPrice = 0;

        // 価格が0より大きい間、価格を合計して、毎回の割引率に従って値段を更新する
        while (price > 0) {
            totalPrice += price; // 価格を合計
            price = (int)Math.floor(price * (100 - discountRate) / 100.0); // 割引率に従って価格を更新
        }

        // 全てのお買い上げの価格を出力
        System.out.println(totalPrice);
    }
}

/*

Scannerを使ってコーヒーの価格と割引率をユーザーに入力してもらいます。

java
Copy code
Scanner scanner = new Scanner(System.in);
int price = scanner.nextInt();
int discountRate = scanner.nextInt();
次に、totalPriceという変数を定義して、お買い上げの価格を累積します。

arduino
Copy code
int totalPrice = 0;
そして、whileループを使って、価格が0より大きい場合は、価格を合計して、
毎回の割引率に従って値段を更新していきます。

arduino
Copy code
while (price > 0) {
    totalPrice += price;
    price = (int)Math.floor(price * (100 - discountRate) / 100.0);
}
Math.floor()メソッドを使用して、小数点以下を切り捨てます。

最後に、全てのお買い上げの価格を出力しています。

csharp
Copy code
System.out.println(totalPrice);
このプログラムは、コーヒーの価格と割引率を入力すると、
全てのお買い上げの価格を出力するものです。

whileループを使って、コーヒーの価格を更新していくことで、
割引率が累積されるようになっています。

*/

