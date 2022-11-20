/*
8 [共通課題] N竜の配置

【氏名】      田村　寛忠
【学籍番号】  201IR077P
【作成日】    2021年8月8日

【仕様／目的】
    コマンドライン入力から正整数 N（4≦N≦11） が与えられたとき、N×
    Nの将棋盤上にN個の竜を互いに「効き」が無いように配置する仕方が何通り可能であるかを求めて、
    標準出力にその値を必要最小限の桁数で１行に書き出すプログラム

【入力】
    ・コマンドライン入力から正整数  N（4≦N≦11）が与えられる。
    ・データの列は、つぎの2つの関数を使って得る。

【出力】
    ・2度以上現れる文字列が存在しなければ、何も出力しないで実行を終了する。
    ・2度以上現れる文字列が存在していれば、現れた回数が最も大きな文字列の出現回数 m を求め、
    　かつ、その出現回数をもつ文字列が何種類存在したかを、
    　つぎの形の１行として標準出力に書き出す。
        m(k)・・・m 出現回数の最大値
                　k その最大回数出現した文字列の種類数
    ・二つの数値 m、k は必要最小限の桁数で書き出す

【構成／アルゴリズム】



【機能保障】


【関数】
     void solve(int x){
     説明   ：
     引数   ：int型
     戻り値 ：なし
     
【参考サイト】
    https://daeudaeu.com/nqueen/
*/


#include <stdio.h>


int P, Q, R;	// 状態変数
char *str;		// 評価する式
int minus(int n)
{
	switch (n) {
		case 0:		return 2;
		case 1:		return 1;
		case 2:		return 0;
	}
}

int multi(int n1, int n2)
{
	if (n1 == 0 || n2 == 0) {
		return 0;
	} else if (n1 == 1 || n2 == 1) {
		return 1;
	} else {
		return 2;
	}
}

int plus(int n1, int n2)
{
	if (n1 == 2 || n2 == 2) {
		return 2;
	} else if (n1 == 1 || n2 == 1) {
		return 1;
	} else {
		return 0;
	}
}

int formula(void)
{
	int f1, f2;
	char enzan;

	switch (*str) {	// 先頭の一文字を見る
		case '0':
			str++;
			return 0;
		case '1':
			str++;
			return 1;
		case '2':
			str++;
			return 2;
		case 'P':
			str++;
			return P;
		case 'Q':
			str++;
			return Q;
		case 'R':
			str++;
			return R;
		case '-':
			str++;
			return minus(formula());
		case '(':
			str++;
			f1 = formula();	// 左辺
			enzan = *str;	// 演算子
			str++;
			f2 = formula();	// 右辺
			str++;	// ')'なので読み飛ばし
			// 計算
			if (enzan == '+') {
				return plus(f1, f2);
			} else {
				return multi(f1, f2);
			}
			break;
	}
}


int main(void)
{
	//<formula> ::= 0 | 1 | 2 | P | Q | R |
    //-<formula> | (<formula>*<formula>) | (<formula>+<formula>)

	int count;
	char buf[1024];

	while (1) {
		scanf("%s", buf);
		if (*buf == '.') {
			break;
		}
		str = buf;

		count = 0;
		for (P = 0; P <= 2; P++) {
			for (Q = 0; Q <= 2; Q++) {
				for (R = 0; R <= 2; R++) {
					str = buf;
					if (formula() == 2) {
						count++;
					}
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}

