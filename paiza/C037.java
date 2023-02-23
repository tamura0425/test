import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] datetime = sc.nextLine().split(" ");

        // 入力値を分割して、月、日、時、分に分ける
        String[] date = datetime[0].split("/");
        int month = Integer.parseInt(date[0]);
        int day = Integer.parseInt(date[1]);

        String[] time = datetime[1].split(":");
        int hour = Integer.parseInt(time[0]);
        int minute = Integer.parseInt(time[1]);

        // 時を修正する
        if (hour > 23) {
            day += hour / 24;
            hour %= 24;
        }

        // 日付がその月に存在しない日になっていた場合も、そのまま出力する
        System.out.printf("%02d/%02d %02d:%02d\n", month, day, hour, minute);
    }
}

/*

与えられた日時を修正するプログラムです。具体的には、入力された日時の「時」の部分を0以上23以下に修正します。修正された日時は、与えられた入力フォーマット「MM/dd hh:mm」に従って出力されます。

最初に、標準入力から受け取った日時を、空白文字で分割して「月」「日」「時」「分」の4つの要素に分けます。これは、splitメソッドを使って、文字列を指定された区切り文字で分割し、配列として取り出すことで行われます。

次に、それぞれの要素を整数型に変換して、変数に代入します。これには、parseIntメソッドを使います。

その後、入力された「時」が23より大きい場合、日数を更新して「時」を修正します。この修正には、剰余演算子と除算演算子を使って、日数と時間を計算します。

最後に、修正された日時をフォーマットに従って出力します。これには、printfメソッドを使用して、指定されたフォーマットで文字列を出力します。 %02dというフォーマット指定子を使うことで、月、日、時、分が2桁の0埋め形式で出力されます。また、最後に改行を出力するために、\nを使用しています。



*/


