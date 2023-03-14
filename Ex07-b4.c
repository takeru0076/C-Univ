#include <stdio.h>
#include <string.h>

char scoretograde(double);

#define SUBJECT_NUM 4 /* 科目数 */
 
typedef struct{
	char id[10];            /* 学籍番号 */
	char name[10];          /* 名前 */
	int score[SUBJECT_NUM]; /* 各点数 */
	int sum;                /* 合計点 */
	double ave;             /* 平均 */
	char grade;             /* 判定 */
}Record;

Record data[20];

int main(int argc, char *argv[]){

    FILE *fp;
    int i,j,l,count;
    char rename[10];

    if(argc == 1){
        fprintf(stderr,"Error!  Usage: ./a.out datafilename\n");
        return 0;
    }

    fp = fopen(argv[1],"r");

    if (fp == NULL)printf("no\n");

    for(i = 0; i < 20; i++){
        if ((fscanf(fp,"%s%s%d%d%d%d",data[i].id,data[i].name,&data[i].score[0],&data[i].score[1],&data[i].score[2],&data[i].score[3])) == -1)
        {
            break;
        }
        data[i].sum = data[i].score[0] + data[i].score[1] + data[i].score[2] + data[i].score[3];
        data[i].ave = (double)data[i].sum / (double)SUBJECT_NUM;
        data[i].grade = scoretograde(data[i].ave);
    }

    for ( j = 0; j < i; j++)
    {
        printf("%s  %s  %d  %d  %d  %d  %d  %.1f  %c\n",data[j].id,data[j].name,data[j].score[0],data[j].score[1],data[j].score[2],data[j].score[3],data[j].sum,data[j].ave,data[j].grade);
    }

    while(1){
        printf("Input a student name/ID: ");  
        if(scanf("%s",rename) == -1)break;
        count = 0;
        while (count < i)
        {
            if(strcmp(data[count].name,rename)==0 || strcmp(data[count].id,rename)==0){
                printf("%s  %s  %d  %d  %d % d % d  %.1f  %c\n",data[count].id,data[count].name,data[count].score[0],data[count].score[1],data[count].score[2],data[count].score[3],data[count].sum,data[count].ave,data[count].grade);
                break;
            }
            count++;
        }
        if(count == i){
            printf("This student does not exist!\n");
        }
    }

    fclose(fp);

    return 0;
}


char scoretograde(double x){
    if(80 <= x && x <= 100){
        return 'A';
    } else if(65 <= x && x <= 79){
        return 'B';
    }else if(50 <= x && x <= 64){
        return 'C';
    }else if(35 <= x && x <= 49){
        return 'D';
    } else {
        return 'F';
    }
}
