

//氏名
//田村寛忠

//作成日
//2021/071

//仕様

/*
ボート屋の1日分の記録ボートの貸出/返却の記録が標準入力に与えられる。 
記録を全て読み取りその日のボート貸出時間の総計を計算して標準出力に書き出すプログラム。 

以下、作成要件

１：読み込んだ１行の文字の列から、sscanf によってその4個の項目（ボートの名前、貸出/返却の別、時刻の時・分）の値を読み出そうとした時にエラーが生じた（ sscanf が 4 でない値を返してきた†）とき
２：ボートの名前として読み取れたのが正当なボート番号（A〜Z のどれか）になっていないとき
３：貸出/返却の別として読み取れたのが正当な出入表示（O または I）になっていないとき
４：時刻が正当なものでない（8≦ 時＜18でない††　または　0≦分＜60 でない）とき
５：その記録がボートの貸出／返却の記録として不当なものであるとき （直前の記録の時刻よりも前の時刻になっている、 貸出記録がないのに返却記録が現れた、 返却記録の時刻が貸出記録の時刻よりも前の時刻になっているなど）
*/

#include <stdio.h>

int main(int argc, char *argv[]){
    //ディファイン定義
    #define STRSIZE 100
    //
    char line[STRSIZE];
    //時
    int hour;
    //分
    int minutes;
    //ボート番号
    char no;
    //賃貸
    char rent;
    //行数
    int n;
    //時間
    int time;
    //エラーフラグ
    int err=0;
    int boat_name;
    ///A～Zの船番と貸し出しフラグ 
    int ship[100][2]={};
    int ret=0;
    //ループカウンター
    int j=1;
    //ループカウンター
    int i;
    
    //1標準入力が尽きるまでループする
    //2配列に入れる
    for(n=1,time=0;fgets(line,STRSIZE,stdin)!=NULL;n++){
        //⃣項目数確認
        if(sscanf(line,"%c %c %2d:%2d\n",&no,&rent,&hour,&minutes)!=4){
            //⃣4項目なければ標準エラーに出力し処理を継続
            fprintf(stderr,"%d: %s",n,line);
            err++;
            continue;
            //continueでスキップ
        }
        //貸出ボートの名前を確認する
        boat_name=no;//
        //船番確認エラー
        if(boat_name<65||90<boat_name){
        	//エラー出力
            fprintf(stderr,"%d: %s",n,line);
            //continueでスキップ
            err++;continue;
        }
        //船番OK貸借確認
        if(65<=boat_name||boat_name<=90){
        //貸出か返却で分岐
            switch(rent){
                //返却
                //貸出していないのでエラー
                case'I':
                	if(ship[boat_name][0]==0){
                    	fprintf(stderr,"%d: %s",n,line);
                    	err++;
                    	break;
                    }
                //返却の場合、貸出フラグを消して時間を計算
                ship[boat_name][0]-=1;
                	time+=60*hour+minutes;
                	break;
                //貸出
                //貸出中の為エラー
                case'O':
                	if(ship[boat_name][0]==1){
                    	fprintf(stderr,"%d: %s",n,line);
                    	err++;
                    	break;
                    }
                //貸出の場合貸し出しフラグを立てて時間を記録
                ship[boat_name][0]+=1;
                time-=60*hour+minutes;
                break;
                //それ以外でエラー
                default:fprintf(stderr,"%d: %s",n,line);
                break;
            }
        }
    }
    //ボートの状況を確認
    for(i=65;i<91;i++){
        if(ship[i][0]==1){
        	ret++;
        	if(j==1){
        	    printf("no return: ");
        	}
        	if(1<j&&j<26){
        	    printf(",");
        	}
            printf("%c",(char)i);
            j++;
        }
    }
    //no return:があったら改行する
    if(ret>=1){
    	printf("\n");
    }
    //エラー出力
    if(err!=0){
    	printf("error report in stderr\n");
    	return 0;
    }
    //時間表示
    printf("%d:%02d\n",time/60,time%60);
    	ret=0;
    return 0;
}

