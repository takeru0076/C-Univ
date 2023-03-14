#include <stdio.h>
#include <string.h>
#include "prog01.h"

int main(){


Record data;

char a[20],b[20];

printf("データを入力してください\n");

printf("苗字 -> ");   scanf("%s",a);   strcpy(data.familyname,a);

printf("名前 -> ");   scanf("%s",b);   strcpy(data.firstname,b);

printf("生まれた年（西暦） -> ");   scanf("%d", &data.birthday[0]);

printf("生まれた月 -> ");   scanf("%d", &data.birthday[1]);

printf("生まれた日 -> ");   scanf("%d", &data.birthday[2]);

printf("性別（0: 男性, 1: 女性） -> ");   scanf("%d", &data.gender);

printf("\n");

printf("苗字: %s\n",data.familyname);

printf("名前: %s\n",data.firstname);

printf("生年月日: %d/%d/%d(",data.birthday[0],data.birthday[1],data.birthday[2]);

if(data.gender == 0){
    printf("male)\n");
} else{
    printf("female)\n");
}

}