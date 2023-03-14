#include <stdio.h>
#include <string.h>
#include "prog01.h"

Record input(void);
void output(Record);


int main(){
Record data;

data = input();
printf("\n");
output(data);

return 0;
}

Record input (void){
char a[20],b[20];
Record data;

printf("データを入力してください\n");

printf("苗字 -> ");   scanf("%s",a);   strcpy(data.familyname,a);

printf("名前 -> ");   scanf("%s",b);   strcpy(data.firstname,b);

printf("生まれた年（西暦） -> ");   scanf("%d", &data.birthday[0]);

printf("生まれた月 -> ");   scanf("%d", &data.birthday[1]);

printf("生まれた日 -> ");   scanf("%d", &data.birthday[2]);

printf("性別（0: 男性, 1: 女性） -> ");   scanf("%d", &data.gender);

return data;
}

void output(Record r){

printf("苗字: %s\n",r.familyname);

printf("名前: %s\n",r.firstname);

printf("生年月日: %d/%d/%d(",r.birthday[0],r.birthday[1],r.birthday[2]);

if(r.gender == 0){
    printf("male)\n");
} else{
    printf("female)\n");
}
}