#include <stdio.h>

int main(){
    char s;
    int status;

    printf("Input any characters:");
    while(1){
    status = scanf("%c",&s);
   if (s == '\n')break;
    printf("ASCII code of '%c' is %d(0x%x).\n",s,s,s);
    }
    return 0;
}