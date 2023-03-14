#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isAlpha(char c);

int main(){
    int judge;
    char s;

    printf("Input any characters:");
    while(1){

    scanf("%c",&s);

    if (s == '\n')break;

    printf("ASCII code of '%c' is %d(0x%x).",s,s,s);

    judge = isAlpha(s);

    if(judge == TRUE){
        printf(" It's an alphabetic character.\n");
    }

    if(judge == FALSE){
        printf(" It's a non-alphabetic character.\n");
    }
    }
    return 0;
}

int isAlpha(char c){
    if( (c>='a'&& c<='z') || (c>='A' && c<='Z'))
    {
    return TRUE;
    }
    else
    {
        return FALSE;
    }

}