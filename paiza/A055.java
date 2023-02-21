package paiza;

import java.util.Scanner;

public class Test {
    static int H, W;
    static char[][] grid;
    static boolean[][] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        W = sc.nextInt();
        grid = new char[H][W];
        visited = new boolean[H][W];
        int sx = 0, sy = 0;
        for (int i = 0; i < H; i++) {
            String s = sc.next();
            for (int j = 0; j < W; j++) {
                grid[i][j] = s.charAt(j);
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }
        sc.close();

        if (dfs(sx, sy)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    static boolean dfs(int x, int y) {
        if (x < 0 || x >= H || y < 0 || y >= W) {
            // 範囲外に出た場合は探索を中止する
            return false;
        }
        if (grid[x][y] == '#') {
            // 巨大な柱にぶつかった場合は探索を中止する
            return false;
        }
        if (visited[x][y]) {
            // すでに探索した場所に戻らないようにする
            return false;
        }
        visited[x][y] = true;
        if (x == 0 || x == H - 1 || y == 0 || y == W - 1) {
            // グリッドの外に出た場合は探索を中止してYESを返す
            return true;
        }
        // 上下左右の4方向について探索する
        boolean result = dfs(x - 1, y) || dfs(x + 1, y) || dfs(x, y - 1) || dfs(x, y + 1);
        return result;
    }
}


/*
深さ優先探索を使用、
現在位置から上下左右の4つの方向を探索し、
自由に行き来できるマスに移動することができるかどうかを判定します。
ただし、すでに探索したマスには戻らないようにします。
また、グリッドの範囲外に出た場合も探索を中止します。
 */


