//氏名
//田村寛忠

//作成日
//2021/07/25

//仕様

/*

標準入力に与えられた行それぞれについて、
順に、正しい入力行の形をしているかどうかを調べ、
正しい形をしていれば、その式の値を計算して結果の値を必要最小限の桁数で書き出し改行を書き出す。

正しい形をしていないときは、ERROR: に続いて、
その最初に検出した要因に応じてつぎのメッセージを左詰で書き出し、改行を書き出す。
「( 式 」の後に ) が現れないとき:　no )
項 が現れるべき位置に数値も ( も現れていないとき:　no number, no (
式 の後ろに（空白を無視して）改行が現れていないとき:　no LF

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
/*
戻り値　int型
引　数　なし
*/
int ter

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
/*
戻り値　int型
引　数　なし
*/
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

