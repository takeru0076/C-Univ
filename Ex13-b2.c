#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLACK '1'
#define WHITE '0'

char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
char **pbm_read(int *, int *);
void   pbm_write(char **, int, int);
char **pbm_erode(char **, int, int);  /* エロージョンを行う関数 */
char **pbm_dilate(char **, int, int); /* ダイレーションを行う関数 */

int main(){
  char **pbm1, **pbm2;
  int ix,iy;

  pbm1 = pbm_read(&ix,&iy);
  if(pbm1==NULL){
    fprintf(stderr,"Invlid image format.");
    exit(1);
  }

  #ifdef ERODE
  pbm2=pbm_erode(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
  #elif DILATE
  pbm2=pbm_dilate(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
  #else
  pbm2=pbm1;
  #endif

  /* 画像を書きだす */
  pbm_write(pbm2,ix,iy);
  /* 画像領域の解放 */
  pbm_free(pbm2,ix,iy);
  return 0;
}

char **pbm_alloc(int x, int y) {
        char **data;

  data=(char **)malloc(y*sizeof(char *));
  if(data==NULL){
      return NULL;
  }
  for(int i=0;i<y;i++){
    data[i]=(char *)malloc(x*sizeof(char));
    if(data[i]==NULL){
        break;
    }
    if(i!=y){
        i--;
        while(i>=0){
            free(data[i]);
        }
        free(data);
        return NULL;
    }
  }
  return data;
}

void pbm_free(char **pbm, int x, int y){
  for(int i=0;i<y;i++){
    free(pbm[i]);
  }
  free(pbm);
}

char **pbm_read(int *x, int *y){
  int x_size,y_size,flg;
  char **data;

  if(getchar()!='P' || getchar()!='1'){
    return NULL;
  }
  scanf("%d",&x_size);
  scanf("%d",&y_size);
  data=pbm_alloc(x_size,y_size);
  if(data==NULL){
      return NULL;
  }
  for(int i=0;i<y_size;i++){
    for(int j=0;j<x_size;j++){
      flg=scanf("%c",&data[i][j]);
      if(flg!=1){
        pbm_free(data,x_size,y_size);
        return NULL;
      }
      if(data[i][j]!=WHITE && data[i][j]!=BLACK){
        pbm_free(data,x_size,y_size);
        return NULL;
      }
    }
  }
  *x=x_size;
  *y=y_size;
  return data;
}

void pbm_write(char **pbm, int x, int y){
  printf("P1\n");
  printf("%d %d\n",x,y);
  for(int i=0;i<y;i++){
    for(int j=0;j<x;j++){
      printf("%c ",pbm[i][j]);
    }
    printf("\n");
  }
}

char **pbm_erode(char **pbm, int x, int y){
    char **a,i1,i2,j1,j2;
    a=pbm_alloc(x,y);
    if(a==NULL){
        return NULL;
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(i==0){
                i1=pbm[i][j];
           }else{
                i1=pbm[i-1][j];
            }
            if(i==y-1){
                i2=pbm[i][j];
            }else{
                i2=pbm[i+1][j];
            }
            if(j==0){
                j1=pbm[i][j];
            }else{
                j1=pbm[i][j-1];
            }
            if(j==x-1){
                j2=pbm[i][j];
            }else{
                j2=pbm[i][j+1];
            }
            if(i1==BLACK && i2==BLACK && j1==BLACK && j2==BLACK && a[i][j]==BLACK){
                a[i][j]=BLACK;
            }else{
                a[i][j]=WHITE;
            }
        }
    }
    return a;
}

char **pbm_dilate(char **pbm, int x, int y){
    char **a,i1,i2,j1,j2;
    a=pbm_alloc(x,y);
    if(a==NULL){
        return NULL;
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(i==0){
                i1=pbm[i][j];
            }else{
                i1=pbm[i-1][j];
            }
            if(i==y-1){
                i2=pbm[i][j];
            }else{
                i2=pbm[i+1][j];
            }
            if(j==0){
                j1=pbm[i][j];
            }else{
                j1=pbm[i][j-1];
            }
            if(j==x-1){
                j2=pbm[i][j];
            }else{
                j2=pbm[i][j+1];
            }
           if(i1==BLACK || i2==BLACK || j1==BLACK || j2==BLACK || pbm[i][j]==BLACK){
                a[i][j]=BLACK;
            }else{
                a[i][j]=WHITE;
            }
        }
    }
    return a;
}


