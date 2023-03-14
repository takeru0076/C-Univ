#include <stdio.h>

int main(){
    int phai = 10530000, e = 137,x = 1;
    double d;

    while(x < phai){

        d = (double)(phai * x + 1) / e;

        printf("d = %f, x = %d\n",d,x);

        x++;
    }
    return 0;
}