#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TATE 5

int main()
{
  int i,j,len;
  char str[100],*arr[TATE];

  for(i = 0; i < TATE; i++){
      printf("Input word #%d: ",i+1);   scanf("%s",str);
      len = strlen(str);
      arr[i] = malloc(sizeof(int) * len);

      strcpy(arr[i],str);
  }
  
  for(i = 0; i < TATE; i++){
    printf("Word #%d: %s\n", i+1, arr[i]);
  }


  
  for(i = 0; i < TATE; i++) free(arr[i]);

  return 0;
}