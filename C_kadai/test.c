
#include  <stdio.h> 
#include  <stdlib.h>

//------------------------------------------------ 
char ch;
int n;

//------------------------------------------------
int main(int argc, char *argv[]){
    printf("文字を入力してください = ");
    /* アルファベットか数字かを判定 */
    while( (ch = getchar()) != EOF ){
            if(ch == '@'){
            printf("OK");
            printf("\n");
        }
        else{
            printf("NG");
            printf("\n");
        }
    }
    return 0;
}

