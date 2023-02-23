import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 1回戦の組み合わせとタイムを読み込む
        int p1 = sc.nextInt();
        int p2 = sc.nextInt();
        int p3 = sc.nextInt();
        int p4 = sc.nextInt();
        int[] times = new int[4];
        for (int i = 0; i < 4; i++) {
            times[i] = sc.nextInt();
        }

        // 1回戦の勝者を求める
        int[] winners = new int[2];
        if (times[p1-1] < times[p2-1]) {
            winners[0] = p1;
        } else {
            winners[0] = p2;
        }
        if (times[p3-1] < times[p4-1]) {
            winners[1] = p3;
        } else {
            winners[1] = p4;
        }

        // 2回戦の勝者を求める
        int winner;
        int f1 = sc.nextInt();
        int f2 = sc.nextInt();
        if (times[winners[0]-1] < times[winners[1]-1]) {
            winner = winners[0];
        } else {
            winner = winners[1];
        }

        // 優勝者と準優勝者を出力する
        if (f1 < f2) {
            System.out.println(winner);
            System.out.println((winner == winners[0]) ? winners[1] : winners[0]);
        } else {
            System.out.println((winner == winners[0]) ? winners[1] : winners[0]);
            System.out.println(winner);
        }
    }
}
