#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isAlpha(char c);
int isLower(char c);

int main(){
    int judge1, judge2;
    char s;

    printf("Input any characters:");
    while(1){

    scanf("%c",&s);

    if (s == '\n')break;

    printf("ASCII code of '%c' is %d(0x%x).",s,s,s);

    judge1 = isAlpha(s);
    judge2 = isLower(s);

    if(judge1 == TRUE && judge2 == FALSE){
        printf(" It's an upper-case character.\n");
    }else if(judge1 == TRUE && judge2 == TRUE)
    {
        printf(" It's a lower-case character.\n");
    } else{
        printf("It's a non-alphabetic character.\n");
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

int isLower(char c){
    if(c>='a'&& c<='z')
    {
    return TRUE;
    }
    else
    {
        return FALSE;
    }
}