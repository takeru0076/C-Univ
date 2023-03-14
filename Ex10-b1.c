#include <stdio.h>
#include <stdlib.h>

#define N 4

int myatoi(char *);

int main(){
    int toshi,i,tem = 0,d;
    char wareki[N];

printf("和暦（H30, R1等）:  ");
    scanf("%s",wareki);
    toshi = myatoi(wareki);

    if(wareki[0] == 'R'){
        toshi = 2019;
    } else if(wareki[0] == 'H'){
        toshi = 1989;
    } else if(wareki[0] == 'S'){
        toshi = 1926;
    } else if(wareki[0] == 'T'){
        toshi = 1912;
    } else if (wareki[0] == 'M'){
        toshi = 1868;
    } else {
        printf("元号の文字が変です\n");
        exit(1);
    }

    for(i = 1; wareki[i] !=  '\0'; i++){
        d = (int)wareki[i] - 48;
        tem *= 10;
        tem += d;
    }


    if(wareki[0] == 'R' && ('0' <= wareki[1] && wareki[1] <= '9')){  
        toshi += tem;
        toshi -= 1; 
        printf("西暦 (A.D.): %d\n",toshi);
    } else if(wareki[0] == 'H' && ('0' <= wareki[1] && wareki[1] <= '9')){
        toshi += tem;
        toshi -= 1;
        printf("西暦 (A.D.): %d\n",toshi);
    } else if(wareki[0] == 'S' && ('0' <= wareki[1] && wareki[1] <= '9')){
        toshi += tem;
        toshi -= 1;
        printf("西暦 (A.D.): %d\n",toshi);
    } else if(wareki[0] == 'T' && ('0' <= wareki[1] && wareki[1] <= '9')){
        toshi += tem;
        toshi -= 1;
        printf("西暦 (A.D.): %d\n",toshi);
    } else if(wareki[0] == 'M'  && ('0' <= wareki[1] && wareki[1] <= '9')){
        toshi += tem;
        toshi -= 1;
        printf("西暦 (A.D.): %d\n",toshi);
    } else {
        printf("数字を読み取れません\n");
        exit(2);
    }

    return 0;
}




int myatoi(char *c){
    int i,j,ch_1 = 0,ch_2= 0,res = 0,d;

    for(i = 0; c[i] != '\0'; i++);

    for(j = 0; j < i;j++){
        if(c[j] == ' '){
            continue;
        }

        if(c[j] == '-'){
            ch_1++;
            continue;
        }

        if(ch_1 == 1 && c[j] == '+'){
            return 0;
        }

        if(c[j] < '0' && '9' < c[j]){
            break;
        }

        if(ch_2 != 0 && (c[j] < '0' || '9' < c[j]))break;

        if(c[j] >= '0' && '9' >= c[j]){
            d = (int)c[j] - 48;
            res *= 10;
            res += d ;
            ch_2++;
        }
    }

    if(ch_1 == 1){
        res *= -1;
    }
    return res;
}