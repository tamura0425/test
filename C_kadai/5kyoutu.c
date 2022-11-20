//氏名
//田村寛忠

//作成日
//2021/05/15

//仕様

/*
    標準入力に与えられた値ををすべて読み取り、
    その中に現れた数値表現全てについてその表す値の総計を計算し,
    その値を最小限の桁数で1行として標準出力に書き出すプログラム。
    
    ここで数値表現とは、数字だけが並んだもので、その前後には数字が現れていず、
    前には記号 + または - があってもよいとする。
    数値表現は、十進表現で値を表していて、
    その前について + または - があればそれは表す値の符号を示しているとする。
*/

#include <stdio.h>
//「標準入出力ライブラリのヘッダファイル
//（stdio.h）を取り込み
#include <stdint.h>
//一定の大きさを持つ整数型を定義してある
//ヘッダファイルです。
#include <inttypes.h>
//コンパイル環境に関係なく、
//明示的にサイズ指定されたデータ項目との
//互換性を持たせるのに役立つ定数、
//マクロ、​派生型が含まれています
#include <math.h>
// math.h. 数学関数と数学定数を利用する
#include <string.h>
//文字列. string.h. 文字列関数を利用する場合しよう

#include <stdlib.h>
//汎用の関数群を実装する。

//ディファイン定義
#define NUBMER (10000)

//プログラム開始
// int main(int argc, char *argv[]){
   int main(void) {
    //変数定義
    
    char strList[NUBMER]={'0'};
    char change[NUBMER]={'0'};
    char ch;
    int i=0;
    int j = 0;
    int k = 0;
    int flag = 1;
    int sum = 0;

    i = 0;
    //標準入力値を全て配列に入れる
    while( (ch = getchar()) != EOF ){
        //入力値から余分なものを取り除く
        if((ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||
            ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='+'||ch=='-' ||ch=='.' ||ch==':')){
            strList[i]=ch;
        }
        i++;
    }

    //配列データがなくなるまでループを行う
    for (i = 0; i <= sizeof(strList); i++){
        //配列データの判定
        if (strList[i] >= '0' && strList[i] <= '9'){
            //数字の場合、その数字がマイナス符号を持つかを確認
            if (strList[i - 1] == '-'){
                //マイナスの場合、flag変数を-1にする
                flag = -1;
            }
            change[j] = strList[i];
            j++;
        }
        //数値ではないのでchar型の配列データをint型に変換する
        else{
            //数値の累積を計算
            sum = sum + (atoi(change) * flag);

            //初期化
            flag = 1;
            j = 0;
            for (k = 0; k <= NUBMER; k++){
                change[k] = ' ';
            }
        }
    }

    //出力結果表示
    printf("%d\n", sum);
    //プログラム終了 
    return 0;

}
