#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 90000
typedef struct{
	int data[N]; /* N個の要素を持つ配列 */
	int max;     /* データの最大値 */
	int min;     /* データの最小値 */
	double ave;  /* データの平均値 */
}My_Array;

void FindMember1(My_Array *);
My_Array FindMember2(My_Array);


int main(){
    srand((unsigned int)time(NULL));

    My_Array A;
    int i;
    time_t start_time1, end_time1,start_time2, end_time2;
    double keika1,keika2;
    for (i = 0; i < N; i++)
    {
        A.data[i] = rand() % 1000;
    }

    start_time1 = clock();
    FindMember1(&A);
    end_time1 = clock();

    printf("FindMenber1\n");
    printf("Maximum value: %d\n",A.max);
    printf("Minimum value: %d\n",A.min);
    printf("Average value: %f\n\n",A.ave);
    
    start_time2 = clock();
    A = FindMember2(A);
    end_time2 = clock();

    printf("FindMenber2\n");
    printf("Maximum value: %d\n",A.max);
    printf("Minimum value: %d\n",A.min);
    printf("Average value: %f\n\n",A.ave);

    keika1 = (end_time1 - start_time1)/(double)CLOCKS_PER_SEC;
    keika2 = (end_time2 - start_time2)/(double)CLOCKS_PER_SEC;
    printf("--- time ---\n");
    printf("FindMenber1:%lf sec\n",keika1);
    printf("FindMenber2:%lf sec\n",keika2);
    
    return 0;
}

void FindMember1(My_Array *a)
{
    int i;
    for ( i = 0; i < N; i++)
    {
        if(a->data[i] > a->max){
            a->max = a->data[i];
        } 
        if(a->data[i] < a->min){
            a->min = a->data[i];
        }

        a->ave += (double)a->data[i];
    }

    a->ave /= (double)N;
}

My_Array FindMember2 (My_Array a)
{
    int i;
    for ( i = 0; i < N; i++)
    {
        if(a.data[i] > a.max){
            a.max = a.data[i];
        } 
        if(a.data[i] < a.min){
            a.min = a.data[i];
        }

        a.ave += (double)a.data[i];
    }

    a.ave /= (double)N;

    return a;
}