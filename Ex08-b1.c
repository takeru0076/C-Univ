#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
}XY;

typedef struct{
    XY center;
    XY p;
    double r;
}CIRCLE;

CIRCLE input1(void);
void input2(CIRCLE *);

int main(){
    CIRCLE data1,data2;
    double length_1,area_1,length_2,area_2;
    printf("データの入力 (構造体を返す関数) :\n");
    data1 = input1();

    length_1 = 2 * M_PI * data1.r;
    area_1 = M_PI * data1.r * data1.r;

    printf("input1: length, area : %f, %f\n",length_1,area_1);


    printf("データの入力(構造体ポインタを使う関数\n");
    input2(&data2);

    length_2 = 2 * M_PI * data2.r;
    area_2 = M_PI * data2.r * data2.r;

     printf("input2: length, area : %f, %f\n",length_2,area_2);

    return 0;
}


CIRCLE input1(void){    
    CIRCLE re_data1;
    XY ten1,ten2;

    scanf("%lf%lf%lf%lf",&ten1.x,&ten1.y,&ten2.x,&ten2.y);

    re_data1.center = ten1;
    re_data1.p = ten2;
    re_data1.r = sqrt((ten2.x-ten1.x)*(ten2.x-ten1.x)+(ten2.y-ten1.y)*(ten2.y-ten1.y));
    return re_data1;
}


void input2(CIRCLE *re_data2){
    XY ten1,ten2;
    scanf("%lf%lf%lf%lf",&ten1.x,&ten1.y,&ten2.x,&ten2.y);
    re_data2->center = ten1;
    re_data2->p = ten2;
    re_data2->r = sqrt((ten2.x-ten1.x)*(ten2.x-ten1.x)+(ten2.y-ten1.y)*(ten2.y-ten1.y));
}