/*
 5  [選択課題] 隣接リスト－復習

【氏名】      田村　寛忠
【学籍番号】  201IR077P
【作成日】    2021年8月5日

【仕様／目的】
    コマンドライン入力からファイル名が与えられ、
    そのファイルにグラフの頂点数と枝の情報が収められているとするとき、
    そのグラフの隣接リストを標準出力に書き出すプログラ。

【入力】
    ・ 与えられたファイル名のファイルの最初の行には、頂点数が与えられる。
    ・ 頂点には、0から始まる番号が振られている。
    ・ 以後の行それぞれには、2個の番号が与えられる。
    ・ その二つの番号の頂点を結ぶ枝があることを表す。
    ・ 与えられる頂点数は35である。

【出力】
    ・ 隣接リストの書出しは頂点の番号 0,1,... の順にそれぞれ１行として書き出す。
    ・ 各行は頂点の番号を最小桁数で書き出した後ろに : を書く。
    ・ その頂点から出ている枝があれば、: に続けて、枝先の頂点の番号全てを若い方から順に書き出す。
    ・ このとき、それぞれの番号は -> に続けて最小桁数で書き出すこと。
    ・ 頂点から枝が出ていてもいなくても、最後に . を書き出して改行を行うこと。

【構成／アルゴリズム】



【機能保障】


【関数】
     void solve(int x){
     説明   ：
     引数   ：int型
     戻り値 ：なし
     
【参考サイト】

*/

#include <stdio.h>
#include <stdlib.h>

#include "ITEM.h"
// int型に対するもの

typedef 
  struct node{
    Item item;
    struct node *next;
  }
LISTnode;

typedef LISTnode *LIST;

LIST create(int m, LIST p){
  LIST q= calloc(1,sizeof(LISTnode));
  assign(m,q->item); q->next= p;
  return q;
}

LIST add(int m, LIST p){
  if( p==NULL ){
    return create(m,(LIST)NULL);  
  } 
  if( equal(m,p->item) ){
      return p;   
  }
  if( less(m,p->item) ){
    return create(m, p);  
  } 
  else{
    p->next= add(m, p->next); return p;
  }
}

int N;
LIST *adj;

int main(int argc, char *argv[]){
  FILE *f= fopen(argv[1],"r");
  if( f==NULL ){
      printf("can't open: %s\n",argv[1]); exit(-1);
      
  }
  fscanf(f, "%d", &N); int i; int m1, m2;
  
  adj= calloc(N,sizeof(LIST));
  for(i= 0; i!=N; i++){ 
      adj[i]= NULL;
  }
  for(; fscanf(f,"%d%d",&m1,&m2)==2;){
    adj[m1]= add(m2,adj[m1]); adj[m2]= add(m1, adj[m2]);
  }
  for(i= 0; i!=N; i++){ LIST p;
    printf("%d:",i); p= adj[i];
    if( p!=NULL ){ 
       printf("->%d", p->item);
       for(p= p->next; p!=NULL; p= p->next) printf("->%d", p->item);
    }
    printf(".\n");
  }
  return 0;
}

