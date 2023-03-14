#include <stdio.h>

int fibo(int);

int main(){
    int n,fib;

    printf("n=");  scanf("%d",&n);

    fib = fibo(n);
    printf("fibonacci(%d) = %d\n",n,fib);

    return 0;
}

int fibo(int n){
    static int check = 0;
    check++;

    printf("called %d times: n=%d\n",check,n);

    if(n == 0 || n == 1){
        return 1;
    } else {
        return fibo(n-1) + fibo(n-2);
    }
}