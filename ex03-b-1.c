#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(){
    double max = 0, min = DBL_MAX, tem;
    FILE *fpin, *fpout;

    if((fpin = fopen("input02.txt", "r")) == NULL){
      printf("failed, inout\n");
      exit(1);
    }

    if((fpout = fopen("output02.txt", "w")) == NULL){
       printf("failed, output\n");
        exit(2);
    }

    while((fscanf(fpin,"%lf",&tem)) != EOF){
        if(tem > max){
            max = tem;
        }

        if(tem < min){
            min = tem;
        }
    }

    fprintf(fpout,"max = %.3f, min = %.3f\n",max,min);

    fclose(fpout);
    fclose(fpin);

    return 0;
}