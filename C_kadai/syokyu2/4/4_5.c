/*
開発環境: 　4-5 [選択課題] 月曜土曜素因数（ICPC）

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


int prime[300001];

int isDoyou(int n)
{
	switch (n % 7) {
		case 1:
		case 6:
			return 1;
		default:
			return 0;
	}
}

void furui(void)
{
	int i, j;

	for (i = 1; i <= 300000; i++) {
		prime[i] = 0;
	}
	for (i = 2; i <= 300000; i++) {
		if (isDoyou(i) && prime[i] == 0) {
			for (j = 2; i * j <= 300000; j++) {
				prime[i * j] = 1;
			}
		}
	}
}

int isPrime(int n)
{
	switch (n % 7) {
		case 1:
		case 6:
			return prime[n] == 0;
		default:
			return 0;
	}
}


int isDoyouSosuu(int n)
{
	int i;

	if (isDoyou(n)) {
		for (i = 2; i < n; i++) {
			if (isDoyou(i) && n % i == 0)
				return 1;
		}
	}
	return 0;
}

int main(void)
{
	
	furui();
	while (1) {
		int i, n;

		scanf("%d", &n);
		if (n == 1)
			break;

		printf("%d:", n);
		for (i = 1;  7 * i - 1 <= n; i++) {
			if (n % (7 * i - 1) == 0 && isPrime(7 * i - 1)) {
				printf(" %d", 7 * i - 1);
			}
			if (n % (7 * i + 1) == 0 && isPrime(7 * i + 1)) {
				printf(" %d", 7 * i + 1);
			}
		}
		printf("\n");
	}
	return 0;
}

