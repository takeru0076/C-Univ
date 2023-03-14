#include <stdio.h>
 
int main(){
    double x = 3.0, y = 1.5;
    double *p, *q;

    p = &x;
    q = &y;

    
 
    printf("Value of x: %f, Address of x: %p\n", *p, p);
    printf("Value of y: %f, Address of y: %p\n", *q, q);
    printf("Product: %f\n", *p * *q);
    printf("Quotient: %f\n", *p / *q);
    return 0;
}