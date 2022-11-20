/*
作成日：2021/7/28
作成者：田村寛忠

【仕様】

コマンドラインから非負整数 n（ 0≦n＜100 ）が与えられると、 
gn を計算しその値を必要最小限の桁数で左詰に１行として書き出す。

※計算は long int 型で行う。

※以下の漸化式で定義される数列 gn を考える。
g(0) = 0, g(1) = 0, g(2) = 1
g(n+3) = g(n+2) + g(n+1) + g(n)

※機能保障

入力100以上の場合
終了


※入力100以下の場合

コマンドライン入力
2
標準出力
1↵

コマンドライン入力
11
標準出力
149↵

コマンドライン入力
23
標準出力
223317


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define none (-1)
long int f_(int n);

//既出解記録用
long int *F;

//f関数配列の領域を確保、配列初期化、領域の開放を行う
long int f(int n){
    //繰り返し用意
    int i;
    //戻り値用
    long int r;
    
    //既出解記録用
    F = calloc(n+1, sizeof(long int)); 
    
    //iが0～nまで処理を繰り返す
    for(i=0;i!=n+1;i++){
        //noneで配列データを初期化
        F[i] = none;
    }
    r = f_(n);
    //確保していた領域を解放する
    free(F);
    return r;
}

//数式の数列を計算、計算すみの値を配列に格納する
long int f_(int n){
    //既に計算済みかどうか
    if(F[n]!=none) {
        //戻り値を配列に入れる
        return F[n];
    }
    
    //計算済みであれば再利用すればよい
    if(n<=1){
        //仕様によりg(0)=g(1)=0
        return F[n] = 0;   
    } 
    else if(n==2){
        //仕様によりg(2) = 1
        return F[n] = 1;  
    }
    //数列を計算後、配列にいれる
    return F[n] = f_(n-1) + f_(n-2) + f_(n-3);
}

int main(int argc, char* argv[]){
    //コマンドラインから受け取り
    int n = atoi(argv[1]);
    
    // n（ 0≦n＜100 ）の規定により
    if(n<100){
        //出力
        printf("%ld\n",f(n)); 
    }
    //入力値が100以上の為終了
    else{
    
        exit(0);
    }

}


