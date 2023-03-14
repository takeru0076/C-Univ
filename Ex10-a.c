#include <stdio.h>

int myatoi(char *);

int main()
{
  char str2[][20]={"  2021",
                   " -80.18",
                   "+32K",
                   " -888,654",
                   "+-24",
                   "x86",
                   "2022/02/28",
                   ""};
  int ival, i;

  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("String:%s\n", str2[i]);
    printf("Value:%d\n", ival);
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