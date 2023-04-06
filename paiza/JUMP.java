import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<ArrayList<Integer>> dh = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            int tmp1 = sc.nextInt();
            int tmp2 = sc.nextInt();
            tmp.add(tmp1);
            tmp.add(tmp2);
            dh.add(tmp);
        }

        ArrayList<Integer> d = new ArrayList<Integer>();
        ArrayList<Integer> h = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            d.add(dh.get(i).get(0));
            h.add(dh.get(i).get(1));
        }

        ArrayList<Double> a = new ArrayList<Double>();
        for (int i = 0; i < m; i++) {
            double tmp = sc.nextDouble();
            a.add(tmp);
        }
        Collections.sort(a, Collections.reverseOrder());

        int c = 600;

        System.out.println(binarySearch(a, d, h, c, m));
    }

    public static boolean check(ArrayList<Double> a, ArrayList<Integer> d, ArrayList<Integer> h, int c, int i) {
        boolean flag = true;
        double jump = 0;
        for (int j = 0; j < d.size(); j++) {
            double left = d.get(j) - Math.sqrt((c - h.get(j)) / a.get(i)) - Math.sqrt(c / a.get(i));
            double left_on = left + 2 * Math.sqrt(c / a.get(i));
            double right = d.get(j) + Math.sqrt((c - h.get(j)) / a.get(i)) - Math.sqrt(c / a.get(i));
            if (jump < left) {
                jump = left_on;
            } else if (jump <= right) {
                jump = jump + 2 * Math.sqrt(c / a.get(i));
            } else {
                flag = false;
                break;
            }
        }
        return flag;
    }

    public static int binarySearch(ArrayList<Double> a, ArrayList<Integer> d, ArrayList<Integer> h, int c, int m) {
        int left = -1;
        int right = m;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (check(a, d, h, c, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }
}


/*
このコードは、AtCoder社が提
供する競技プログラミングの問題「Frog Jump」という問題に対する解法です。この問題は、池に沈むことのないように青蛙が浮島を渡るために、浮島間の距離と高さ、青蛙が跳べる高さに関する情報が与えられると、青蛙が跳べる高さを最大化することが目的です。

このコードでは、二分探索を用いて青蛙が跳べる高さを最大化しています。具体的には、最小値を left、最大値を right とし、その中間点を mid として、mid が条件を満たすかどうかをチェックしていきます。その際、check 関数を定義し、青蛙が跳べる高さを a[i] としたときに、青蛙が浮島を渡ることができるかどうかを調べています。

check 関数では、まず、フラグを1に初期化します。その後、各浮島について、左側にある点を left、ジャンプした後の左側の点を left_on、右側にある点を right と定義します。ここで、left_on はジャンプした後に到達する左側の点を表します。jump は青蛙が前回ジャンプした位置を表し、初期値は0に設定します。

各浮島について、jump が left より小さい場合は、青蛙はそのままジ
ャンプします。ジャンプした後、left_on に位置するかど
うかを確認します。もし left_on よりも右側にいた場合は、ジャンプします。もし right よりも右側にいた場合は、フラグを0に設定し、チェックを終了します。

最後に、while ループで条件を満たす最大のインデックスを探して、その値を出力しています。

なお、このコードでは、浮動小数点数を使用しているため、誤差が生じる可能性があります。


*/






