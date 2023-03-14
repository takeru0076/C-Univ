#include <stdio.h>
#include <string.h>
#include "prog01.h"

Record input(void);
void output(Record);
int getage(Record);


int main(){
Record data[2];
int i,age[2];

printf("--------データ入力--------\n");
for(i = 0; i  < 2;  i++){
printf("%d人目のデータを入力してください\n",i+1);
data[i] = input();
printf("\n");
age[i] = getage(data[i]);
}



printf("--------データ出力--------\n");
printf("年齢基準日: 2021/10/1\n");

for(i = 0; i < 2; i++){
output(data[i]);
printf("年齢:%d\n\n",age[i]);
}

return 0;
}




Record input (void){
char a[20],b[20];
Record data;

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

int getage(Record data){
    if(data.birthday[1] >= 10 || data.birthday[1]  == 1 || data.birthday[1] == 2 || data.birthday[1] == 3){
        return 2021 - data.birthday[0] - 1;
    } else {
        return 2021 - data.birthday[0];
    }
}