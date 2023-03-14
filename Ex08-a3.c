#include <stdio.h>

#define N 20

typedef struct{
	int id;        /* ID */
	char name[10]; /* 名前 */
	int grade;     /* 学年 */
	int score;     /* 点数 */
	char record;   /* 成績 */
}StudentInfo;
void PrintInfo1(StudentInfo);
void PrintInfo2(StudentInfo *);
int InputData(StudentInfo *);


int main(){
    int i,a,j;
    StudentInfo data[N];


for(i = 0;i < N; i++){
    a = InputData(&data[i]);
    if(a != 6)break;
}


    printf("構造体の値渡し\n");
    for(j = 0; j < i; j++){
    PrintInfo1(data[j]);
    }

    printf("構造体の参照渡し\n");
    for(j = 0; j < i; j++){
    PrintInfo2(&data[j]);
    }

    return 0;
}

int InputData(StudentInfo *data){
    int status;
    char g;
    status = scanf("%d%s%d%d%c%c",&data->id,data->name,&data->grade,&data->score,&g,&data->record);
    return status;
}


void PrintInfo1(StudentInfo data)
{

    printf("%d %s %d %d %c\n",data.id, data.name, data.grade, data.score, data.record);
}




void PrintInfo2(StudentInfo *data)
{
     printf("%d %s %d %d %c\n",(*data).id, (*data).name, (*data).grade, (*data).score, (*data).record);
}