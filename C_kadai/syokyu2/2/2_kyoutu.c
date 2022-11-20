//氏名
//田村寛忠

//作成日
//2021/071

//仕様

/*
コマンドラインから日付（年・月・日）が与えられたとき、
その日の曜日を出力するプログラム。

１：　年(1900〜2100)、月(1〜12)、日(1〜31) は、空白で区切られてに並んでいる。
２：　出力する曜日は、略号3文字（Sun、Mon、Tue、Wed、Thu、Fri、Sat)を
　　　左詰にした１行として出力に。
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>

    //構造体作成　年月日
    typedef struct{
        int year,month,day;
    } date_type;
    
    int days(date_type *d){
        int Y,M,D;
            Y = d->year; /*「構造体ポインタ->「メンバ名」*/
            M = d->month;D=d->day;
        
        if(M==1||M==2){
            M+=12;Y--;
        }
        /*入力されたデータを計算する*/
        return (365*(Y-1926)+(Y/4)-(Y/100)+(Y/400)+(int)(30.6*(M+1))+D-525);
    }
    
    /*ある月のカレンダーを表示する。*/
    /*その月の1日の曜日(日->0,・・・,土->6を求める*/
    int first_day_of_month(date_type *d){
        date_type temp=*d;
        temp.day=1;
    return(days(&temp)%7);
    }
    
    /*その月の日数を求める*/
    /*days(翌月の1日)-days(その月の1日)*/
    int days_in_month(date_type *d){
        date_type temp1,temp2;
        temp1=temp2=*d;
        temp1.day=temp2.day=1;
        temp1.month++;
    return days(&temp1)-days(&temp2);
    }
    
    /*カレンダーを表示する*/
    /*土曜日を書いたら改行する*/
    /*main関数*/
    int main(int argc,char *argv[]){
        date_type birthday,*today;
    int day_of_week,w,i,n;
    int new_line=0;
    
    //曜日を配列に入れる
    char *youbi[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    
    if(argc != 3){
        fprintf(stderr,"usage>birth Y M \n");
        exit(1); /*強制終了 終了コード=1*/
    }
    
    /*コマンドラインから入力された年月を代入*/
    birthday.year = atoi(argv[1]);
    birthday.month = atoi(argv[2]);
    
    /**/
    w = first_day_of_month(&birthday);
    n = days_in_month(&birthday);
    
    //曜日出力
    for(i=0;i<7;i++){
        printf(" %3s",youbi[i]);
    }
    
    printf("\n%*s",w*4,"");
    
    for(i=1;i<=n;i++){
        printf(" %3d",i);
        if(++w%7==0){
            printf("\n");
            //最後の改行出力計算
            new_line++;
        }
       
    }
    //最後の改行を出力する
    /*
    　金曜日が最後でないので、最後の改行を入れる
    */
    if(new_line==4){
       printf("\n");  
    }
//プログラム終了
return 0;
}

//
//

//
//

//
//

//
//

//
//

//
//


