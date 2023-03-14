#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * MAXDATA:最大データ数
 * LENIP  :IPアドレスの最長文字数+1
 * LENHOST:最長文字数+1
 */
#define MAXDATA 1024
#define LENIP   16
#define LENHOST 256

int main(){
  int l,i,status;
  int ndata;
  FILE *fp;
  char ipad[MAXDATA][LENIP];
  char hostname[MAXDATA][LENHOST];
  char query[LENHOST];
  /* その他必要な変数を定義して良い */

  /*** データの読み出し処理 ***/
  /* ファイルのオープン */
  fp = fopen("hostlist.txt","r");
  if (fp == NULL) {
    printf("Cannot open file!\n");
    exit(1);
  }
  /* データの読み出し */
  for( i=0; i<MAXDATA; i++ ){
    /* ２項目読めなければループを抜ける */
    if (fscanf( fp, "%s %s",
      ipad[i], hostname[i] ) != 2) break;
  }
  ndata=i;

  /*** 問合せの処理 ***/
  while(1){
    status = scanf("%s",query);
    if(status == EOF)break;
   /* 文字列の配列の使用方法に注意      *
    * hostname[xxx]でxxx番目の文字列を示す */
   for(i = 0; i <= ndata; i++){
     l = strcmp( hostname[i], query );
     if(l == 0){
       printf("%s : %s\n",hostname[i],ipad[i]);
     }
     if(l == 0)break;
     if(i == ndata){
       printf("%s : not found!\n",hostname[i]);
     }
   }
  }

  fclose(fp);

  return 0;
}