#include <stdio.h>
#include <stdlib.h>

#include "ITEM.h"
#include "AM.h"
#include "oracle.h"

int main(int argc, char *argv[]){

//		int d, n;
		int i,m,k,n;
// コマンドラインよりデータ数nを読み込み
    if (argc==0) {
        return 0; 
    }
    n=atoi(argv[1]);
    int d[n];		
	AMinit(n);  // n個分の連想記憶を初期化

    setup(n);

    for (i=0;i<n;i++){
      d[i]=getNo();  
    } 

    for (i=0;i<n;i++) {
        // 連想記憶に配列dを登録
        AMinsert((Item)d[i]); // 連想記憶に配列dを登録
    }
    // 連想記憶より相異なる数mを取得
	m= AMcount(); k=n-m; 
	//　課題の指示に基づき標準出力
    printf("%d: %d\n",m,k);
    
    return 0;
}
    
