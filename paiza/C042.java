import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] results = new int[n][n];

        // 試合結果を入力として受け取る
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            int winner = sc.nextInt() - 1;
            int loser = sc.nextInt() - 1;
            results[winner][loser] = 1;
            results[loser][winner] = -1;
        }

        // 勝敗表を作成する
        for (int i = 0; i < n; i++) {
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    row.append(" -");
                } else if (results[i][j] == 1) {
                    row.append(" W");
                } else if (results[i][j] == -1) {
                    row.append(" L");
                } else {
                    row.append("  ");
                }
            }
            System.out.println(row.toString().trim());
        }
    }
}

Scanner クラスを使って、整数 n を入力します。

n は、参加チームの数です。次に、n * (n - 1) / 2 回、勝ったチームと負けたチームの情報を入力します。
入力された情報を元に、results 配列に勝敗の結果を保存しています。
results 配列は、n 行 n 列の二次元配列であり、results[i][j] には、チーム i がチーム j に勝った場合は 1、負けた場合は -1、引き分けの場合は 0 が入っています。

次に、二重ループを使って勝敗表を作成しています。最初のループで、各チームごとに行を作成しています。
まず、StringBuilder クラスを使って、空の文字列を作成します。
そして、内側のループで、各チームとの勝敗を調べて、row 変数に適切な文字列を追加していきます。

チームが自分自身である場合は、" -" を追加し、勝った場合は " W"、負けた場合は " L" を追加します。引き分けの場合は、" "（半角スペース2つ）を追加します。
ループが終わったら、row 変数に入っている文字列の先頭と末尾にある余分なスペースを取り除き、System.out.println() を使って出力します。

このようにすることで、各行の末尾に余分なスペースが出力されることを避けることができます。



このコードでは、n人の参加者があり、それぞれが対戦相手と試合を行います。ただし、各人が1回ずつ試合を行い、重複した試合を行わないようにします。したがって、合計試合数はn(n-1)/2となります。このため、試合結果を入力として受け取るためのループは、iが0からn(n-1)/2-1まで実行される必要があります。具体的には、n人が参加する場合、最初の人はn-1回、次の人はn-2回、...、最後の人は0回試合を行うため、n-1 + n-2 + ... + 1 + 0 = n(n-1)/2回の試合が行われます。このため、forループの条件式は、i < n(n-1)/2となります。

