#include <stdio.h>
#include <string.h>
#include "prog01.h"

#define N 20

Record input(void);
void output(Record);
int getage(Record);


int main(){
Record data[N];
int i = 0,j = 0;

while(1){
data[i] = input();
if(data[i].gender == -1)break;
i++;
}



printf("--------データ出力--------\n");
printf("年齢基準日: 2021/10/1\n");

for(j = 0; j < i; j++){
printf("%d人目のデータ:",j+1);
output(data[j]);
}

return 0;
}




Record input (void){
Record data;

if(scanf("%s%s%d%d%d%d",data.familyname,data.firstname,&data.birthday[0],&data.birthday[1],&data.birthday[2],&data.gender) == -1){
    data.gender = -1;
}
return data;
}





void output(Record r){
    int age;

    age = getage(r);

printf("%s      %s      , 生年月日: %d/%d/%d, 年齢: %d ",r.familyname,r.firstname,r.birthday[0],r.birthday[1],r.birthday[2],age);

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