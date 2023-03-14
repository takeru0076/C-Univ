#include <stdio.h>
int main(){
    char s;
    printf("Input a character:");
    scanf("%c",&s);
    printf("ASCII code of '%c' is %d(0x%x).\n",s,s,s);
    return 0;
}