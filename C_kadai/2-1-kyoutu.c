/*
学籍番号：181IR080K
氏名：金子　拓人
作成日：202107014
仕様
　ボート貸出時間の総計を計算して標準出力に書き出すプログラム
　ボートの名前、貸出/返却の別、時刻
　ボートの名前は英大文字１字
　貸出/返却の別は英大文字１字で O が貸出を、I が返却
　時刻は24時間制の時・分がそれぞれ2桁
　（値が0〜9の時には頭に数字0を補って）表され、
　時・分の間に : が置かれている。 ボートの貸出/返却の記録は、
　時刻の順に並んでいる。
アルゴリズム

　1⃣標準入力から一行を読み取る
　2⃣配列に入れる
　3⃣4項あるか確認する
　5⃣なければエラーフラグをたてる
　6⃣貸出ボートの名前を確認する
　7⃣ボートの名前をイント型にする
　8⃣貸出を確認する
　9⃣0であれば配列に時間を入れる
　⑩既に貸し出し中ならエラー
　⑪0の前にiがきたらエラー
　⑫ioを先に読み込んでボートの貸出状況を確認する
　ASCIIコード表より65～90はA～Zを表す
*/
//コーディング
#include <stdio.h>

int main(int argc, char *argv[]){
    
    #define LINESIZE 100//設定ラインサイズ100
    char line[LINESIZE];//配列ライン100
    int h,m;//時と分
    char b,io;//号と貸借
    int n,tm;//行数と時間
    int err=0;//error flag
    int bb;
    int ship[100][2]={};//A～Zの船番と貸し出しフラグ 
    int ret=0;int j=1;int i;
    //1⃣標準入力が尽きるまでループする
    //2⃣配列に入れる
    for(n=1,tm=0;fgets(line,LINESIZE,stdin)!=NULL;n++){
        //3⃣4項あるか確認する
        if(sscanf(line,"%c %c %2d:%2d\n",&b,&io,&h,&m)!=4){
            //5⃣4項なければ標準エラーに出力し処理を継続
            fprintf(stderr,"%d: %s",n,line);err++;continue;//continueでスキップ
        }
        //6⃣貸出ボートの名前を確認する
        bb=b;//7⃣int cast
        if(bb<65||90<bb){//船番確認エラー
            fprintf(stderr,"%d: %s",n,line);//エラー出力
            err++;continue;//continueでスキップ
        }
        if(65<=bb||bb<=90){//8⃣船番OK貸借確認
            switch(io){//貸出か返却で分岐する
                //返却
                case'I':if(ship[bb][0]==0){//貸出していないのでエラー
                    fprintf(stderr,"%d: %s",n,line);err++;break;}
                //返却の場合、貸出フラグを消して時間を計算
                ship[bb][0]-=1;tm+=60*h+m;break;
                //貸出
                case'O':if(ship[bb][0]==1){//貸出中の為エラー
                    fprintf(stderr,"%d: %s",n,line);err++;break;}
                //貸出の場合貸し出しフラグを立てて時間を記録
                ship[bb][0]+=1;tm-=60*h+m;break;
                //それ以外でエラー
                default:fprintf(stderr,"%d: %s",n,line);break;
            }
        }
    }
    //閉店の準備
    for(i=65;i<91;i++){//すべてのボートの状況を確認
        if(ship[i][0]==1){ret++;if(j==1)printf("no return: ");if(1<j&&j<26)printf(",");
        printf("%c",(char)i);j++;//貸し出しフラグがあったらchar型で出力
        }
    }
    if(ret>=1)printf("\n");//no return:があったら改行する
    if(err!=0){printf("error report in stderr\n");return 0;}//エラーフラグありでエラー出力
    printf("%d:%02d\n",tm/60,tm%60);ret=0;//時間表示
    return 0;
}

