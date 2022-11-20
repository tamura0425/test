#include <stdio.h>

int recursion(int n){
    return n+(n-1);
    }

int main(void){
int xM = 1;

xM = recursion(xM);

printf("x=%d, \n", xM);

return 0;
}
