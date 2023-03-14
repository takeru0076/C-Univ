#include <stdio.h>
#include <stdlib.h>



int main()
{
  int num, i;
  double firstval, lastval,dif;
  double *x;

  printf("Input First value, Last value, Total number: ");
  scanf("%lf%lf%d", &firstval, &lastval, &num);


  x = (double *)malloc(num * sizeof(double));

    dif = (lastval - firstval)/ (double)(num -1);
    x[0] = firstval;
    for(i = 1; i < num; i++){
        x[i] = x[i-1] + dif;
    }

  printf("Value of x\n");
  for(i = 0; i < num; i++){
      printf("%.3f ",x[i]);
  }

  printf("\n");

  printf("Value of x^2\n");
  for(i = 0; i < num; i++)
  {
      printf("%.3f ",x[i]*x[i]);
  }

  printf("\n");

  free(x);
  
  return 0;
}



