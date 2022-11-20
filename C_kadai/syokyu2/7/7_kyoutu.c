/*
  7 [共通課題] 全点支配木 - グラフ操作の総合

【氏名】      田村　寛忠
【学籍番号】  201IR077P
【作成日】    2021年8月15日

【仕様／目的】
    グラフについての情報とそのグラフの頂点の番号が与えられたとき、
    その頂点から幅優先探索で作成した全点支配木の深さと、
    その頂点から深さ優先探索で作成した全点支配木の深さを出力する。
※
    ・ グラフの頂点数と枝の情報を示すファイルの名前がコマンドラインから与えられる。
　  ・ ファイルの最初の行には、頂点数が与えらる。
　  ・ 頂点には、0から始まる番号が振られている。 
　  ・ 以後の行それぞれには、2個の番号が与えられる。 
　  ・ その二つの番号の頂点を結ぶ枝があることを表す

【入力】。
　  ・ 与えられる頂点数は、35である。
　  ・ 準入力から、いくつかの頂点の番号が与えらる。 

【出力】
    与えられた頂点の番号ごとに、その頂点を出発点として、 
    幅優先探索で作成した全点支配木の深さ、深さ優先探索で作成した全点支配木の深さを、 
    つぎに示す形で1行として書き出す。
    
    その番号に続けて“)”
    空白1文字と“BFS:”に続けて、幅優先探索で作成した全点支配木の深さ
    空白1文字と“DFS:”に続けて、深さ優先探索で作成した全点支配木の深さ
    ただし、番号・深さは、それぞれ必要最小限の桁数で書き出すこと。
    
    ※
    なお、「幅優先探索」・「深さ優先探索」だけではそれで作る全点支配木が一意には決まらない。
   　それぞれの頂点からは、枝先の頂点の番号の若いものから順にたどって、
   　最初に全ての点に達したときに得られる全点支配木を対象とする。 
   　
　　「全点支配木の深さ」とは、 作られた全点支配木の中で出発点からの経路長がもっとも大きい頂点の経路長をいう。

【構成／アルゴリズム】
・コマンドラインの第1引数からファイル名を読み取る
・読み取ったファイルを読み取り専用で開く
・ファイルの読み取りエラーがあった場合。プログラムを終了
・ファイルの1行目から頂点の個数Nを読み取る
・ファイルの2行目以降を読み取り、2つの頂点情報m1・m2を隣接リストに追加する
・標準入力より頂点番号ｐを読み取る
・pが0より小さいまたN以上場合プログラムを終了
・幅優先検索のためBFS関数を呼び出す
・幅優先探索における全点支配木の深さを判定
・深さ優先検索のためDFS関数を呼び出す
・頂点番号、幅優先探索で作成した全点支配木の深さ、深さ優先探索で作成した
　全点支配木の深さを出力する


【機能保障】
・コマンドラインの第1引数(0相対)で指定されたファイルが存在しないなどの場合、
　メッセージを表示し、プログラムを終了している
・標準入力から入力した頂点番号が、0より小さくファイルの先頭で指定された
　頂点個数N以上の場合、処理自体は行わず、プログラムを終了している
・幅優先検索で作成した全点支配木は、同じステップ数で行けるところをまず全て
　訪問するようにしている
・深さ優先検索で作

【関数】
     LIST create(int m, LIST p){
     説明   ：ﾃﾞｰﾀをポインタに変化する
     引数   ：int型
     戻り値 ：なし
     
    LIST add(int m, LIST p){
     説明   ：各データを状況に合わせて関数に関数に渡す
     引数   ：int型
     戻り値 ：なし
     
    void show(int p, int q, int n){
     説明   ：データが一致すれば表示する
     引数   ：int型
     戻り値 ：なし
     
    void BFS(int p){
     説明   ：各データのルート確認
     引数   ：int型
     戻り値 ：なし    
     
    void DFS(int q,int fromD,int depthD){
     説明   ：深さを比較
     引数   ：int型
     戻り値 ：なし    
     
     
     
【参考サイト】
鎗田　英一さんの記載方法を参考にさせていただきました。
*/

#include <stdio.h>
#include <stdlib.h>
#include "ITEM.h" 


typedef 
    struct node{
        Item item;
        struct node *next;
    }
LISTnode;

typedef LISTnode *LIST;

LIST create(int m, LIST p){
    LIST q= calloc(1,sizeof(LISTnode));
    assign(m,q->item); 
    q->next= p;
    return q;
}

LIST add(int m, LIST p){
    if( p==NULL ){
        return create(m,(LIST)NULL);
    }
    if( equal(m,p->item) ){
      return p;  
    } 
    if( less(m,p->item) ) {
        return create(m, p);
    }
    else{
        p->next= add(m, p->next); 
        return p;
    }
}

int N;
LIST *adj; int *visited;
LIST *adjDFS; int *visitedDFS;
int *from; int *depth;
//深さ優先探索の深さ
int depthDFS=0;

#include "QUEUEITEM.h"
#include "QUEUE.h"

void show(int p, int q, int n){
    if( q==p ){
        printf("%d: %d",n,p); return;
    }
    show(p,from[q],n+1);
    printf("->%d", q);
}

void BFS(int p){
    QUEUEItem d;
    QUEUEput((QUEUEItem){p,-1});
    for(;QUEUEcount()!=0;){
        d= QUEUEget(); 
        if( visited[d.to]==1 ){
            continue;
        }
        visited[d.to]= 1; from[d.to]= d.from;
        depth[d.to]= (d.from<0? 0: depth[d.from]+1);
        LIST p= adj[d.to];
        for(; p!=NULL; p= p->next){
            QUEUEput((QUEUEItem){p->item, d.to}); 
        }
    }
}

void DFS(int q,int fromD,int depthD){
    if( visitedDFS[q]==1 ) return;

    visitedDFS[q]= 1;
    if( depthD!=0 ){
        //depthDの方が大きければ、深さを更新
        if(depthDFS<depthD){
            depthDFS = depthD;
        }
    }
    LIST p= adjDFS[q];
    for(; p!=NULL; p= p->next){
        DFS(p->item,q,depthD+1); 
    }
}

int main(int argc, char *argv[]){
    
    FILE *f= fopen(argv[1],"r");
    if( f==NULL ){
        printf("can't open: %s\n",argv[1]);
        exit(-1);
    }
    
    fscanf(f, "%d", &N);
    
    int i; int m1, m2;
    adj= calloc(N,sizeof(LIST));
    adjDFS= calloc(N,sizeof(LIST));
    for(i= 0; i!=N; i++){
        adj[i]= NULL;
        adjDFS[i]= NULL;
    }
    visited= calloc(N,sizeof(int));
    visitedDFS = calloc(N,sizeof(int));
    from= calloc(N,sizeof(int));
    depth= calloc(N,sizeof(int));

    //ファイルから読み込んだ値をもって行列の組み合わせを作成する
    for(; fscanf(f,"%d%d",&m1,&m2)==2;){
        /*i,jの組合せがある限り、m1にはm2が接続している、
        m2にはm1が繋がっている*/
        
        /*幅優先探索用*/
        adj[m1]= add(m2, adj[m1]); 
        adj[m2]= add(m1, adj[m2]);
        /*深さ優先探索用*/
        adjDFS[m1]= add(m2, adjDFS[m1]); 
        adjDFS[m2]= add(m1, adjDFS[m2]);
    }
    fclose(f);
    
    /*phase3*/
    for(i= 0; i!=N; i++){
        LIST p;
        p= adj[i];
        for(; p!=NULL; p= p->next){}
    }

    int p;
    int depthBFS=0;//幅優先探索の深さ

    for(;scanf("%d", &p)==1;){
        QUEUEinit(1000);
        for(i= 0; i!=N; i++){
            visited[i]= 0;
            visitedDFS[i] = 0;
        } 
        DFS(p,-1,0);
        /*幅優先探索を実行*/
        BFS(p);

        for(i= 0; i!=N; i++){
            if( i==p ){
                continue;
            }
            if(depthBFS<depth[i]){
                //depth[i]の方が大きければ、深さを更新
                depthBFS = depth[i];
            }
        }
        printf("%d) BFS:%d DFS:%d\n", p, depthBFS, depthDFS);
        //次の標準入力行の数値の開始点のためにクリアする
        depthBFS=0;
        depthDFS=0;
    }

    return 0;
}

