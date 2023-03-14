#include <stdio.h>
#include <stdlib.h>
int fiboarray(int, int *);

int main(){
    int i,n,fib,*array;

    printf("n=");  scanf("%d",&n);

    array = (int *)malloc(n * sizeof(int));

    for(i = 0; i <= n; i++){
        array[i] = 0;
    }

    fib = fiboarray(n,array);

    printf("fibonacci(%d) = %d\n",n,fib);

    return 0;
}

int fiboarray(int n, int *a){
    static int called = 0;
    called++;

    printf("called %d times: n=%d\n",called,n);
    /*見計算*/
    if(a[n] == 0){
        if(n == 0 || n == 1){
            a[n] = 1;
            return a[n];
        } else {
            a[n] = fiboarray(n-1,a)+ fiboarray(n-2,a);
            return a[n];
        }
    } else {
        /*計算済*/
        return a[n];
    }
}