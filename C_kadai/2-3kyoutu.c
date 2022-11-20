//氏名
//田村寛忠

//作成日
//2021/07/28

//仕様

/*

標準入力から、いくつかの行が与えられたとき、
その全ての行それぞれについて前から順に正しい入力行の形をしているかどうかを調べ、
正しい形をしていればその指示に従った計算や代入を行い、していないなら以下のメッセージを書き出す。

（正しい形になっているかどうかを調べるときには、
    入力中の空白文字を全て無視しなければならないことに注意する。）

１：正しい式の形をしていれば、
　その計算を行ってその結果の数値を必要最小限の桁数で１行として標準出力に書き出す。

２：正しい代入の形をしてれば、
　　直前の計算で得られている数値をその変数に代入する。
　　そして、標準出力に１行として、その変数の名前に続けて、
　　空白1文字、=、空白1文字に続けて代入した値を必要最小限の桁数で書き出す。

３：正しい入力行の形をしていないときは、
　　その最初に検出した要因に応じてつぎのメッセージを「ERROR:」と空白1文字に続けて左詰で
　　１行として書き出し、計算も代入も行わない。

４：行頭の : の後ろに変数が現れないとき　「no variable」
    先頭部分が正しい入力行の形をしているがその後ろ（空白を無視して）に改行が現れないとき「no LF」
    ( 式　に続いて ) が現れないとき　「no )」
    項 が現れるべき位置の先頭に
    数値、変数、( のいずれも現れないとき　「no number, no (」

５：なお、変数は、全て、動作開始時に値を 1 に設定しておくこととする。


※以下の方がのコードを参考にさせていただきました。
釜親　慶多　様
柚木　直人　様
久保田　敦　様

関数：
void init_kind() 
    説明 :  get_token の初期設定; プログラムの先頭で呼び出す
    引数 :  なし。
    返り値 : なし。

void error(char *s) 
    説明 :メッセージ s を標準出力に書き出し、setjmp(env) で設定したところへ飛ぶ
    引数 :  文字列。
    返り値 : なし。

char *get_line() 
    説明 :  fgets(line,LINESIZE,stdin);から、文字のポインタを返す。
    引数 :  なし。
    返り値 : lineの次の文字のポインタを返す。

void get_token() 
    説明 :  読み取ってある行から, 空白を読み捨てて次のトークンを読み出す
			読み出せた次のトークンが何であったかをtokenに入れる
			空白以外の文字は全てそれ一つがトークン
	ただし、数字列はひとまとめにして数値として扱う

    引数 :  なし。
    返り値 : なし。

int expr() :  
    説明 :  tokenに'+'が読み取れれば、term関数の戻り値のtokenの数値を加算して戻す。
            tokenに'-'が読み取れれば、term関数の戻り値のtokenの数値を減算して戻す。
    引数 :  なし。
    返り値 : term関数の戻り値を加算、もしくは減算した数値を戻す。

int term() : 
    説明 :   tokenが数値もしくは、英字ならばnum_valueを戻す。
            記号( ならば、expr関数の結果を戻す。
            記号）が検出されなければ、error関数に文字列を渡す。
    引数 :  なし。
    返り値 : num_valueの値を戻す。


機能保障：
1：標準入力にある半角スペースは飛ばす。
2：課題文にある「数値」は０で代表し、「変数」はｘで代表して処理を行う。
3：代入は記号：を検出して処理する。
4：記号(のあとに、記号)が読み取れないときは、エラーとする。
5：改行が読み取れないときは、エラーとする。
6：エラーがあれば処理を抜けて、課題文に従って標準出力に書き出す。
7：入力がなければ標準出力には出力しない。
以上の保証により、このコードは問題ないと思われる。
*/


#include <stdio.h>
#include <setjmp.h>
#include <ctype.h>


#define LINESIZE 100

char line[LINESIZE];// 処理中の行
int ch, cp;// ch: 次の文字、cp: そのline中の位置

// 各文字に対するトークンとして番号
char kind[128];
//variable['A']〜variable['Z'] と 
int variable[128];
//variable['a']〜variable['z'] の52個の要素
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
char token;// 読み取れたトークン（数値のときは '0'　英字のときは'1'）
int  num_value;  //数値の表す値
int  alpha_value;//変数の表す値

void init_kind();
// get_token の初期設定; プログラムの先頭で呼び出す

void process();  // 1行の処理
int expr();  // 式　の処理
int term();  // 項　の処理
int assingment(); //代入かどうかのチェックしてトークンの取得
int storeResult;//数値計算格納用（グローバルにしないと警告される）

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
    
    //最初のトークンを読み出しておいてから処理する
    get_token();
    
    if(token == ':'){
        assingment();
        if( token!='\n'){
            error("no LF");  
        }
        variable[alpha_value] = storeResult;
        printf("%c = %d\n", alpha_value, storeResult);
    }
    else{
        result= expr();
        if( token!='\n'){
            error("no LF");  
        }
        storeResult = result;
        printf("%d\n",result);
    }
}

int expr(){
  
  //・・・式　に対する処理
  int t1, t2;

  t1 = term();
  while(token=='+' || token=='-'){
    //printf("%c\n", token);
      char op = token;
      get_token();
      t2 = term();
      switch(op){
        case '+':
            t1+=t2;
            break;
        case '-':
            t1-=t2;
            break;
      }
  }
  return t1;
}

int term(){
    //項に対する処理
    int v;
    switch(token){
        case '(':
            get_token();
            v=expr();
            if(token!= ')' ){
                error("no )");
            }
            get_token();
            break;
        case '0':
            v = num_value;
            get_token();
            break;
        case '1':
            if(('A' <= alpha_value)&&(alpha_value <= 'Z')) {
                v = variable[alpha_value];
            }
            else if(('a' <= alpha_value)&&(alpha_value <= 'z')){
                v = variable[alpha_value];
            }
            get_token();
            break;
        default:
            error("no number, no (");
    }
    return v;
}

int assingment(){
    get_token();
    
    if(token != '1'){
        error("no variable");
    }

    get_token();
    return 0;
}

void error(char *s){
  printf("ERROR: %s\n",s);
  longjmp(env, -1);
}


// 初期設定：ここでは、数字'0'、英字'1'を番号とする
void init_kind(){
  int i;
  for(i= 0; i!=128; i++){
    kind[i]= i;
    //変数は動作開始時に全て1とする
    variable[i] = 1;
    //数字だったら、0をいれる
    if( isdigit(i) ) kind[i]= '0';
    //英字だったら、1をいれる
    if( isalpha(i) ) kind[i]= '1';

  }
}

//ポインタ
char *get_line(){
    char *mode= fgets(line,LINESIZE,stdin);
    cp= 0; ch= line[cp++];
    return mode;
}

#define val(c)  (c-'0')

void get_token(){
  // 空白文字を読み捨てる（最後は '\n' で終わる
        while( ch==' ' ) ch= line[cp++];
  // 読めた文字そのものをトークンとする
        token= kind[ch];

  // ただし、数字のときは、数字が続く限り読み取り
  // 1個の数値として扱い、その表す数値を num_value に入れる
        switch( token ){
            case '0':
                num_value= val(ch);
                ch= line[cp++];
                while( kind[ch]=='0' ){
                    num_value= num_value*10+val(ch);
                    ch= line[cp++];
                }
                break;
            case '1':
                alpha_value = ch;
                ch= line[cp++];
                break;
            default:
                ch= line[cp++]; break;
        }
}

