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

int main(){
    srand((unsigned int)time(NULL));

    My_Array A;
    int i;
    for (i = 0; i < N; i++)
    {
        A.data[i] = rand() % 1000;
    }

    FindMember1(&A);
    printf("main\n");
    printf("Maximum value: %d\n",A.max);
    printf("Minimum value: %d\n",A.min);
    printf("Average value: %f\n",A.ave);

    
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

    printf("FindMenber1\n");
    printf("Maximum value: %d\n",a->max);
    printf("Minimum value: %d\n",a->min);
    printf("Average value: %f\n",a->ave);
}