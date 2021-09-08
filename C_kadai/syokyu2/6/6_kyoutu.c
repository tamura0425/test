
/*
【氏名】      田村　寛忠
【学籍番号】  201IR077P
【作成日】    2021年8月15日


【仕様／目的】/仕様
    n個の文字列からなるデータの列が与えられたとき、
    全てを読み取って相異なる値が何個あったか、を調べるプログラム。

【入力】
    コマンドライン入力から正整数 n（ 0 ＜ n ≦ 500000 ）が与えられる。
    データの列は、つぎの2つの関数を使って得る。
        void setup(int n);
        char *getStr();
【入力】
    読み取ったデータの列の中の相異なる文字列の個数 mと、
    重複しないデータばかりを残すのにデータの列から取り除くことのできる文字列の個数 k と
    をつぎの形の１行として標準出力に書き出す。
    m: k
    二つの数値 m、k は必要最小限の桁数で右詰に書き出す
    : と k の間に空白1文字をおく
【以下実行例】
    3個のデータ列が "ab" "AB" "cab" であった場合
    コマンドライン入力
    3
    標準出力
    3: 0
    
    5個のデータ列 "" "AB" "AB" "AB" "AB" であった場合
    コマンドライン入力
    5
    標準出力
    2: 3
【構成／アルゴリズム】
    コマンドラインから2個目のデータを読み込む
    atoiを使用し整数値の文字列型データをint型に変換
    長さ n （int型の）の文字列の長さを設定
    入力値がなくなるまで繰り返しchar型のポインタに代入し,
    C言語のヘッダファイルのAM。hのAMinsertにデータを登録する
    

【関数」
    void setup(int n);
    説明   : 長さ n のデータ列を設定する
    引数   :  int
    返り値 : なし。

    char *getStr();
    説明   : setup で設定されたデータの列から次の文字列を1つ取り出して返してくる
            データの列が尽きているなら NULL を返してくる
    引数   : なし。
    返り値 : char型のポインタ
    
    void AMinsert(Item item);
    説明   ：項目itemを登録する
    引数   : Item item
    返り値 : なし
*/


#include <stdio.h>
#include <stdlib.h>

#include "ITEM.h"
#include "AM.h"
#include "oracle.h"

int main(int argc, char *argv[]){
    // コマンドラインからの入力を読み取る
    int n = atoi(argv[1]);
    // ライブラリoracleを初期化
    setup(n);
    // 連想記憶ライブラリー、AMの初期化
    AMinit(n);
    // getStrで文字列を取り出し、
    // 与えられた連想記憶、AMに格納する、
    char* item;
    for (int i=0; i<n; i++){
        item = getStr();
        AMinsert(item);
    }
    // BinSearchTree.cの53,54行目において
    // すでにある値は挿入されないため、今記憶されている個数が、
    // ユニークな文字列の個数mとなる。
    int m = AMcount();
    // 入力値nからそのユニークな文字列の個数mを引いた値が、
    // 重複により削除されたkになる。
    int k = n - m;
    // 結果を出力
    printf("%d: %d\n", m,k);
    return 0;

}
