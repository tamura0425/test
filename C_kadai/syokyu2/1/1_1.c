//氏名
//田村寛忠

//作成日
//2021/071

//仕様
/*
標準入力から2個の正整数を取得し。 

2個の正整数の最大公約数と最小公倍数を計算し,
それぞれ必要最小桁数で左詰にして1行として、
最大公約数と最小公倍数順に書き出すプログラム。 


*/

//標準入出力ライブラリのヘッダファイル
#include <stdio.h>
//プログラム開始
int main(void){

/*
変数定義
最小公倍数を扱う時にintでは表現しきれない可能性があるため
long int 型を使用
*/
long int a, b, r, x, tmp;

//１つ目のデータ読み取り
scanf("%d", &a);
//２つ目のデータ読み取り
scanf("%d", &b);

x = a * b;

/* 自然数 a > b を確認・入替 */

if(a<b){
    tmp = a;
    a = b;
    b = tmp;
}

/* ユークリッドの互除法 

ユークリッドの互除法は、
2つの自然数から最大公約数を求める手法のことです。

大きい自然数aを小さい自然数bで割った余りをrとすると、
a と b の最大公約数は b と r の
最大公約数に等しくなります。

以下参考サイト
https://webkaru.net/clang/find-gcd-of-two-number/

*/


//最小公倍数を計算
//余りをrに代入
r = a % b;
//余りが無くなるまで繰り返す。
while(r!=0){
    a = b;
    b = r;
    r = a % b;
}

/*最大公約数*/
printf("%d\n",b);
/* 最小公倍数を出力 */
printf("%2ld\n", x/b);


//プログラム終了
return 0;
}
