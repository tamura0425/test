/* つぎの一連の構文規則によって、正しい 式 (expression) の構文が、正しい 項（term）の構文とともに再帰的に定義されているとする。構文規則の中には、数値・数字 に対するものも含まれている。



式　　　＝　項｛ （ +｜- ）項 ｝

項　　　＝　数値　｜　( 式 )

数値　　＝　数字｛ 数字 ｝

数字　　＝　0｜1｜2｜3｜4｜5｜6｜7｜8｜9



ただし、数値 および 記号 + - ( ) の前後には （読み易いように）空白文字を幾つでも補ってよいとする。数値は、十進表現とする。ただし、先頭にいくつか 0 が書いてあるかもしれないので注意する。



　つぎに示す仕様を満たすプログラムを作れ。ただし、このプログラムが書出しを行う先は標準出力とする。

標準入力に与えられた行それぞれについて、順に、
正しい入力行の形をしているかどうかを調べ、正しい形をしていれば、その式の値を計算して結果の値を必要最小限の桁数で書き出し改行を書き出す。
正しい形をしていないときは、ERROR: に続いて、その最初に検出した要因に応じてつぎのメッセージを左詰で書き出し、改行を書き出す。
「( 式 」の後に ) が現れないとき:　no )
項 が現れるべき位置に 数値　も ( も現れていないとき:　no number, no (
式 の後ろに（空白を無視して）改行が現れていないとき:　no LF
　「読み易くするために幾つでも空白文字を補ってよい」という規則から、入力行 が正しい式の形をしているかどうかを検査するにあたってはこうした空白文字を無視する必要があることに注意する。


　なお、式 の値の計算は int型で行うこと。溢れが生じても何の処置もしなくてよい。


式の例
123-(1-3)+5+6
0123 + 004567 + (13 - (25))

実行例
標準入力

1-(2-(3-(4+5))+6)+7

(123-(456-(789-876))-8)-1


標準出力

-6

-429





標準入力

1-((2-3)



-3

[1-2]

1*2-3

(1*2)-3



標準出力

ERROR: no )

ERROR: no number, no (

ERROR: no number, no (

ERROR: no number, no (

ERROR: no LF

ERROR: no )

*/

#include <stdio.h>
#include <setjmp.h>

jmp_buf env;
void error(char *s);
// メッセージ s を標準出力に書き出し、
// setjmp(env) で設定したところへ飛ぶ

char *get_line();
// 次の入力行を読み取る, 
// 戻り値がNULL ⇔　入力行なし
void get_token();
// 読み取ってある行から, 空白を読み捨てて次のトークンを読み出す
// 読み出せた次のトークンが何であったかをtokenに入れる
// 空白以外の文字は全てそれ一つがトークン
// ただし、数字列はひとまとめにして数値として扱う
  char token;
  // 読み取れたトークン（数値のときは '0'）
   int  num_value;
   // 数値の表す値
void init_kind();
// get_token の初期設定; プログラムの先頭で呼び出す

void process();  // 1行の処理
int expr();  // 式　の処理
int term();  // 項　の処理

int main(int argc, char  *argv[]){

  init_kind();
  for(; get_line()!=NULL; ){
    switch( setjmp(env) ){
      case 0:
          process(); // １行に対する処理（スライドのこの部分を関数にした）
          break;
      default: 
          break; // 処理中に間違いを検出した場合の後始末
    }
  }

  return 0;
}

// 1行に対する処理
void process(){
    int result;
    get_token();  // 最初のトークンを読み出しておいてから処理する
    result= expr();
    if( token!='\n') error("no LF");
    printf("%d\n",result);
}

//関数 expr()定義
int expr(){
    int t1, t2;
    t1= term();
    
    while( token=='+' || token=='-' ){
        char op= token; get_token();
        t2= term();
        
        switch( op ){
            case '+': t1+= t2; break;
            case '-': t1-= t2; break;
        }
    }
    return t1;
}

//term() の関数定義
int term(){
    int v;
        switch( token ){
        case '(':
            get_token(); v= expr();
            if( token!=')' ) {
                error("no )");
            }
            get_token(); 
            break;
        case '0':
            v= num_value; get_token(); 
            break;
        default:
            error("no number, no (");
        }
    return v;
}


void error(char *s){
  printf("ERROR: %s\n",s);
  longjmp(env, -1);
}

#include <ctype.h>
#define LINESIZE 100
char line[LINESIZE];
// 処理中の行
int ch, cp;
// ch: 次の文字、cp: そのline中の位置

char kind[128];
// 各文字に対するトークンとして番号

// 初期設定：ここでは、数字だけ '0'を番号とする
void init_kind(){
  int i;
  for(i= 0; i!=128; i++){
    kind[i]= i;
    if( isdigit(i) ) kind[i]= '0';
  }
}

char *get_line(){
  char *mode= fgets(line,LINESIZE,stdin);
  cp= 0; ch= line[cp++];
  return mode;
}
//  スライドで提示したものからはいくつかの行が除いてある。
//  スライドでは、UNIX端末窓での利用を考えて
//  ・プロンプト> を出力する
//  ・空行の入力で終了する
//  ・CTRL-d での入力終了に対して画面上で行を改める
//  が入れてあった 

#define val(c)  (c-'0');
  // 数字 c が表す値 

void get_token(){
  // 空白文字を読み捨てる（最後は '\n' で終わる
        while( ch==' ' ) ch= line[cp++];
  // 読めた文字そのものをトークンとする
        token= kind[ch];
  // ただし、数字のときは、数字が続く限り読み取り
  // 1個の数値として扱い、その表す数値を num_value に入れる
        switch( kind[ch] ){
         case '0':
           num_value= val(ch); ch= line[cp++];
           while( kind[ch]=='0' ){
             num_value= num_value*10+val(ch);
             ch= line[cp++];
           } break;
         default:
           ch= line[cp++]; break;
        }
}



