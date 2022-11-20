//氏名
//田村寛忠

//作成日
//2021/05/1

//仕様

/*
4日間に及ぶゴルフ大会に参加したプレーヤーの成績をすべて読み取り、
最上位の成績をとったプレーヤーの名前をそれぞれ1行として書き出すプログラム。

このとき、名前は first name と family name をこの順に空白1文字で区切る
最上位の成績をとったプレーヤーが複数いれば、それらのプレーヤーの名前をすべて書き出すこと。
その書き出す順は、標準入力に与えられた順とすること。
なお、最上位の成績をとったプレーヤーの人数は最大5名。

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
#define NUBMER (1000)


// 構造体
/*
この定義でプレイヤーの情報を全て保管
*/
typedef struct{
    char firstName[NUBMER];
    char familyName[NUBMER];
    int numScore;
}DATA;
//プログラム開始


//プログラム開始
int main(int argc, char *argv[]){
    
    DATA a[NUBMER];
    
    /*
    int型の最大値を定義
    この手続きで最初に入力されるデータが必ずcountに代入される
    */
    int count = 2147483647;
    //ループカウンター用変数
    int i = 0;
    
    int number=0;
    
    
    //入力データが無くなるまで、ループを繰り返す
    while (EOF != scanf("%s %s %d\n", a[i].firstName, a[i].familyName, &a[i].numScore)){
        /*
        データを比較して、値が小さければcountにデータを入れる
        */
        if(count > a[i].numScore){
            count = a[i].numScore;
        }
        i++;
    }
    
    //ループの終了条件を設定する
    number = i;
    
    //ループカウンターを初期化する
    i = 0;
    
    //成績を表示
    printf("%d\n",count);
    
    //データが無くなるまで、ループを繰り返す
    for(i = 0 ; i <= number ; i++){
        //成績を比較し一致するか判定
        if(a[i].numScore == count){
        /*
        成績上位者のデータを全て表示
        */
            printf("%s %s\n", a[i].firstName, a[i].familyName);
        }
    }
    return 0;
}

