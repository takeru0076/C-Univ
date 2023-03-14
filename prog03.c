#include <stdio.h>

char scoreToGrade(int);
int gradeToPoint(char);


int main(){
    int status,hyoutei, tanni,GP,count=0,sum=0;
    double gpa;
    char s;
    while (1)
    {
        printf("評定と単位数を入力してください(Ctrl+Dで終了):");
        status = scanf("%d%d", &hyoutei, &tanni);
        if(status == -1){
          break;
        }
        s = scoreToGrade(hyoutei);
        GP = gradeToPoint(s);
        count += tanni;
        sum += GP * tanni;
        printf("%d点の評価は%cで、Grade Point(GP)は%dです. (%d単位)\n",hyoutei ,s ,GP ,tanni);
        printf("\n");
    }
    printf("\n");
    gpa = (double)sum / count;
    printf("Grade Point Average (GPA): %.3f,  単位数: %d\n",gpa,count);
        return 0;
}

char scoreToGrade(int x){
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

int gradeToPoint(char y){
    if(y == 'A'){
        return 4;
    }else if(y == 'B'){
        return 3;
    }else if(y == 'C'){
        return 2;
    }else{
        return 0;
    }
}
