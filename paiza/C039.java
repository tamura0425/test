import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        sc.close();
        
        int tens = 0; // 10の位の数
        int ones = 0; // 1の位の数
        int sum = 0;  // 答え
        
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '<') {
                tens++;
            } else if (c == '/') {
                ones++;
            } else if (c == '+') {
                sum += (tens * 10 + ones);
                tens = 0;
                ones = 0;
            }
        }
        // 最後の数の足し算を計算
        sum += (tens * 10 + ones);
        
        System.out.println(sum);
    }
}




/*
このプログラムは、パイザ記法の式を解釈して結果を出力するものです。それぞれの部分について、以下に説明します。

import java.util.Scanner;
java.utilパッケージのScannerクラスをインポートしています。これは、標準入力から文字列を読み込むために使用されます。

public class Main {
Mainクラスを定義しています。Javaプログラムでは、最低限public classを定義して始める必要があります。

public static void main(String[] args) {
Javaプログラムのエントリーポイントであるmainメソッドを定義しています。これは、プログラムの開始地点となります。

Scanner sc = new Scanner(System.in);
Scannerオブジェクトを作成し、System.inを引数として渡しています。これは、標準入力を取得するために使用されます。

String input = sc.nextLine();
ScannerオブジェクトのnextLine()メソッドを使用して、標準入力から文字列を取得します。

sc.close();
Scannerオブジェクトをクローズして、標準入力を解放します。

int tens = 0; // 10の位の数
10の位を表す数字を初期化します。

int ones = 0; // 1の位の数
1の位を表す数字を初期化します。

int sum = 0; // 答え
答えの初期値を0に設定します。

for (int i = 0; i < input.length(); i++) {
文字列の各文字に対してループを開始します。

char c = input.charAt(i);
文字列のi番目の文字を取得し、char型の変数cに代入します。

if (c == '<') { tens++; }
cが<の場合、10の位を表す数字tensをインクリメントします。

else if (c == '/') { ones++; }
cが/の場合、1の位を表す数字onesをインクリメントします。

else if (c == '+') { sum += (tens * 10 + ones); tens = 0; ones = 0; }
cが+の場合、10の位と1の位を合わせて数値に変換し、答えの変数sumに加算します。
その後、10の位と1の位の変数tensとonesをそれぞれ0にリセットします。

sum += (tens * 10 + ones);
最後に残っている10の位と1の位を合わせプログラムを終了します。

このプログラムは、まず標準入力から1行の文字列を受け取ります。

次に、ループを使って文字列の各文字を順番に調べていきます。文字列の各文字に対して、以下の処理を行います。

もし文字が '<' であれば、10の位の数字を表すために tens の値を1増やします。
もし文字が '/' であれば、1の位の数字を表すために ones の値を1増やします。
もし文字が '+' であれば、tens と ones の値を足し算して sum に加え、tens と ones を0にリセットします。
このループが終了した後、最後にtensとonesの値を足し算してsumに加えます。
これは、最後の数字が '+' で終わっていない場合に備えた処理です。

最後に、sumを出力してプログラムを終了します。

このプログラムは、与えられた入力文字列に対して、数式を解釈して足し算を行うという問題を解決するためのものです。
文字列を1文字ずつ処理することで、与えられた数式の各部分を正しく解釈し、最終的な答えを求めることができます。


まず、Scannerクラスを使用してユーザーからの入力を受け取ります。
nextLine()メソッドを使用することで、改行が出現するまでの一行を文字列として読み込みます。
そして、Scannerをclose()メソッドで閉じます。

次に、変数tens、ones、sumを初期化します。
tensは整数の10の位の数、onesは整数の1の位の数、sumはそれまでの数式の計算結果の総和です。

その後、forループを使って、入力された文字列の各文字を1つずつ処理します。
charAt()メソッドを使用して、文字列の各文字を順に取得します。
if-else文を使って、<、/、+のいずれの記号が出現したかに応じて、tensやones、またはsumの値を変更していきます。

<が出現した場合、tensを1増やします。/が出現した場合、onesを1増やします。
+が出現した場合、tensとonesを使って、それまでの整数の10の位と1の位を計算し、sumに加算します。
そして、tensとonesを0にリセットして、次の整数の処理に備えます。

最後に、forループの処理が完了した時点で、最後の整数の処理が残っている場合があります。
そのため、最後にsumに残っているtensとonesの値を使って、最後の整数の計算を行います。

最後に、計算結果のsumをSystem.out.println()メソッドを使って出力し、プログラムを終了します。



*/
