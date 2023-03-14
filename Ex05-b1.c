File Edit Options Buffers Tools C Help                                                                                                                                                                      
#include <stdio.h>
#include <string.h>

#define NWORD 5

int main(){
    char str2[NWORD][20];
    char newstr[100];
    int i,j,length = 0,count = 0;

    printf("Input %d words:\n",NWORD);

    for(i = 0; i < NWORD; i++){
        scanf("%s",str2[i]);
    }

    for(i = 0; i < NWORD; i++){
        strcpy(&newstr[count],str2[i]);
        count += strlen(str2[i]);
        if (i != 4)
        {
        strcpy(&newstr[count]," ");
        count++;
        }
    }

    printf("%s\n",newstr);
    printf("Total: %d characters\n",count);

    return 0;

}