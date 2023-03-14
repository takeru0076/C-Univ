#include <stdio.h>

typedef struct{
	int id;        /* ID */
	char name[10]; /* 名前 */
	int grade;     /* 学年 */
	int score;     /* 点数 */
	char record;   /* 成績 */
}StudentInfo;
void PrintInfo1(StudentInfo);
void PrintInfo2(StudentInfo *);


int main(){
    StudentInfo data[2]= {
    {1290130,"takeru",1, 100, 'A'},
    {1290141, "shouma",1,100, 'A'}
    };


    printf("構造体の値渡し\n");
    PrintInfo1(data[0]);
    PrintInfo1(data[1]);

    printf("構造体の参照渡し\n");
    PrintInfo2(&data[0]);
    PrintInfo2(&data[1]);

    return 0;
}

void PrintInfo1(StudentInfo data)
{

    printf("%d %s %d %d %c\n",data.id, data.name, data.grade, data.score, data.record);
}

void PrintInfo2(StudentInfo *data)
{
     printf("%d %s %d %d %c\n",(*data).id, (*data).name, (*data).grade, (*data).score, (*data).record);
}