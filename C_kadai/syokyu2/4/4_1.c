/*

学籍番号：201IR077P
作成日：2021/7/28
作成者：田村寛忠

[課題]
フィボナッチ数を計算する関数
long int f(int n)を再帰呼出しを使って実装したものに
トップダウンの動的計画法を適用した場合を考える。
与えられた非負整数 n を引数とする関数呼出し f(n) を行なったときに
生じる関数呼出し( f 自身の呼出しそこから（直接に／再帰的に）呼び出される関数の呼出し）の回数を数え、 
計算されたフィボナッチ数とともにその回数を標準出力に書き出すプログラムを作れ。

プログラムの仕様。

１；コマンドライン引数に非負整数値が1個または2個与えられる。　　
２：1個与えられた場合、その値 n を引数として呼出し f(n) を行う。
３：2個与えられた場合、それらの値を m1、m2 とすると m 1 ≦ n ≦ m 2 である全ての値 n について小さい方から順に関数呼出し f(n) を行う。 m1＞m2 のときは関数呼出しは何も行わずに実行を終了する。
４：出力は、関数呼出し f(n) を行うごとにその結果をつぎの形式で1行として標準出力に書き出す。

※
f(n)=v [c　times]
v はフィボナッチ数の値、 c はその関数呼出し回数
v と [ の間、c と times の間には、それぞれ空白1文字をおくこと。
数値 n、v、c それぞれは、必要最小限の桁数で書き出すこと。


関数
long int f(int n){
    説明 　: 配列を作成し結果入れ返す
    引数　 : int型。
    返り値 : int型。


long int f_(int n){
    説明　 : n-1とn-2の答えを返す
    引数 　: int型
    返り値 : int型



*/



#include <stdio.h>
#include <stdlib.h>

long int f_c;
long int f(int n);
// n番目(n>=0)のフィボナッチ数を返す

#define none (-1)
long int f_(int n);
long int *F; 

//メイン関数
int main(int argc, char *argv[]){
    //引数が1
    //コマンドラインからの入力が0の場合はプログラム終了
    if(argc==1) {
        return 0;    
    }
    
    /*
    コマンドラインからの入力値が2つ以上ある場合
    */
    int i;
    int from=atoi(argv[1]);
    int to=from;
    if(argc==3){
        from=atoi(argv[1]);
        to=atoi(argv[2]);
    }
    /*
    終了条件の3つ目の入力値が2つ目の入力値より小さいので
    プログラム終了
    */
    if(from>to){
      return 0;  
    } 
    
    //2つ目の入力を開始値として3つ目の入力値がなくなるまで繰り返す。
    for(i=from; i<=to; i++){
        //入力値が0の場合
        //ｆ関数に送る
        if(i==0){
            printf("f(%d)=%ld [%d times]\n",i,f(i),2);
        }
        //ｆ関数に送る
        //入力値が
        else if(i>=0){
            printf("f(%d)=%ld [%d times]\n",i,f(i),i*2);
        }
    }
    return 0;
}

long int f(int n){
    int i; 
    long int r;
    
    F= calloc(n+1, sizeof(long int));
    
    for(i= 0; i!=n+1; i++){
        F[i]= none;   
    }
    r= f_(n); 
    free(F);
return r;
}


long int f_(int n){
    
    if( F[n]!=none ){
        return F[n];
    }
    if( n<=1 ){
        return F[n]= n;
    }
    
    return F[n]= f_(n-1)+f_(n-2);
}

