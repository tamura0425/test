/*
8 [共通課題] N竜の配置

【氏名】      田村　寛忠
【学籍番号】  201IR077P
【作成日】    2021年8月15日

【仕様／目的】
    コマンドライン入力から正整数 N（4≦N≦11） が与えられたとき、N×
    Nの将棋盤上にN個の竜を互いに「効き」が無いように配置する仕方が何通り可能であるかを求めて、
    標準出力にその値を必要最小限の桁数で１行に書き出すプログラム

【入力】
    ・コマンドライン入力から正整数  N（4≦N≦11）が与えられる。
    ・データの列は、つぎの2つの関数を使って得る。

【出力】
    ・2度以上現れる文字列が存在しなければ、何も出力しないで実行を終了する。
    ・2度以上現れる文字列が存在していれば、現れた回数が最も大きな文字列の出現回数 m を求め、
    　かつ、その出現回数をもつ文字列が何種類存在したかを、
    　つぎの形の１行として標準出力に書き出す。
        m(k)・・・m 出現回数の最大値
                　k その最大回数出現した文字列の種類数
    ・二つの数値 m、k は必要最小限の桁数で書き出す

【構成／アルゴリズム】



【機能保障】


【関数】
     void solve(int x){
     説明   ：
     引数   ：int型
     戻り値 ：なし
     
【参考サイト】
    https://daeudaeu.com/nqueen/
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define BUF_SIZE 300
#define ROW_MAX 90
#define COL_MAX 90
 
int get_int(void) {
  int num;
#ifdef BUF_SIZE
  char line[BUF_SIZE];
  if(!fgets(line, BUF_SIZE, stdin)) return 0;
  sscanf(line, "%d", &num);
#else
#error
#endif
  return num;
}
 
// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(char *arr, int size) {
#ifdef BUF_SIZE
    char line[BUF_SIZE];
    char *tmpbuf = line;
    int i;
    if(!fgets(line, BUF_SIZE, stdin)) return -1;
    for(i = 0; i < size; i++) {
        char *tmp = strtok(tmpbuf, " ");
        arr[i] = (char)strtol(tmp, NULL, 10);
        tmpbuf = NULL;
    }
#else
#error
#endif
    return 0;
}
 
struct point2d {
    int row;
    int col;
};
 
struct point2d dist4[4] = {
    { 1, 0 },
    { -1, 0 },
    { 0, -1 },
    { 0, 1 },
};
 
#define ANS_MAX 200000
int ans[ANS_MAX];
int idx = 0;
 
static char map[ROW_MAX+2][COL_MAX+2];
#define max(a,b) ((a) > (b) ? (a) : (b))
int func(struct point2d start, int cnt) {
    int i;
#ifdef DEBUG
    printf("%d, %d -> %d\n", start.row, start.col, cnt);
#endif
    for(i = 0; i < 4; i++) {
        struct point2d np = {
            start.row + dist4[i].row,
            start.col + dist4[i].col,
        };
        if(map[np.row][np.col]) {
            map[np.row][np.col] = 0;
            // stacked
            ans[idx++] = func(np, cnt+1);
            //ans = max(ans, func(np, cnt+1));
            map[np.row][np.col] = 1;
        }
    }
    return cnt;
}
 
int main(void) {
    int col = get_int();
    int row = get_int();
    int i, j;
    for(i = 1; i <= row; i++) {
        fget_array(&map[i][1], col);
    }
 
    int first = 1;
    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            if(!map[i][j]) continue;
            struct point2d start = {i, j};
            map[i][j] = 0;
            func(start, 1);
            map[i][j] = 1;
            first = 0;
        }
    }
 
    int res = 0;
    for(i = 0; i < ANS_MAX; i++) {
        if(ans[i] > res) res = ans[i];
 
    }
    printf("%d\n", res);
    return 0;
}



