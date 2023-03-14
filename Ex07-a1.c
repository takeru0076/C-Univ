#include <stdio.h>
#include <string.h>

int main(){

struct record{
	char familyname[20]; /* 苗字 */
	char firstname[20];  /* 名前 */
	int birthday[3];     /* 誕生日（要素0: 西暦, 要素1: 月, 要素2:日） */
	int gender;          /* 性別 (0:男性, 1:女性) */
};

char a[20],b[20];
 
struct record data; 

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