#include <stdio.h>
#define INDI 3
#define INDJ 4

int main()
{
  int array[INDI][INDJ] = {
    { 2,  8, 11,  3},
    { 8,  5,  0,  7},
    { 4, 10,  4,  6},
  };
  int i,j,n,count = 0;
  /* 必要に応じて変数宣言を追加 */

  printf("数値を入力してください: ");
  scanf("%d", &n);

  for(i = 0; i < INDI; i++){
      for(j = 0; j < INDJ; j++){
          if(array[i][j] == n){
              printf("array[%d][%d]が%dです\n",i,j,n);
              count = count + 1;
          }
      }
  }

  if(count == 0){
      printf("2次元配列arrayの要素に%dはありません",n);
  }else{
      printf("2次元配列arrayの要素に%dは%d個ありました。",n,count);
  }

 return 0;

}