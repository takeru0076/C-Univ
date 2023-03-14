#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'


char **pbm_alloc(int, int);
void   pbm_free(char **, int, int);
char **pbm_read(int *, int *);
void   pbm_write(char **, int, int);
void   pbm_square(char **, int, int, int, char);

int main(int argc, char *argv[]) {
  char **pbm;
  int i;
  int ix, iy, d;
  /* 標準入力から入力された画像に合わせて領域を確保し、画素を読み込む */
  pbm = pbm_read(&ix, &iy);



  /* 正方形の半辺長を画像サイズに合わせて決める */
  if (atof(argv[1]) < 0.0 || atof(argv[1]) > 1.0) exit(8);
  if (ix>iy) d = (int)(iy * atof(argv[1]) /2);
  else d =  (int)(ix * atof(argv[1]) /2);
  d--;

#ifdef WSQUARE
  /* 白線で正方形を書く */
  pbm_square(pbm, ix, iy, d, WHITE);
#endif
#ifdef BSQUARE
  /* 黒線で正方形を書く */
  pbm_square(pbm, ix, iy, d, BLACK);
#endif

  /* 画像を書きだす */
  pbm_write(pbm, ix, iy);
  /* 画像領域の解放 */
  pbm_free(pbm, ix, iy);
  return 0;
}

/********************************************/
/* 画像データ用の2次元配列確保              */
/* x, y: 確保する2次元配列の大きさ          */
/********************************************/
char **pbm_alloc(int x, int y) {
  char **data;
  int i,j;
  /* この関数は未完成であり、問題2の完成対象である */
  data = (char **)malloc(y * sizeof(char *));
  if(data == NULL){
    return NULL;
  }
  for(i =0; i < y; i++){
              data[i] = (char *)malloc(x * sizeof(char));

    if(data[i] == NULL)break;
  }


  if(i != y){

    for(j = i; j >= 0;j--){
      free(data[j]);
    }

    free(data);
    return NULL;
  }

  return data;
}

void  pbm_free(char **pbm, int x, int y) {
  /* この関数は完成している */
  int i;
  for (i = 0; i<y; i++)
    free(pbm[i]);
  free(pbm);
}

void   pbm_write(char **pbm, int x, int y) {
  /* この関数は完成している */
   int i, j;
  /* 最初にP1とx,yの画素数を出力 */
  printf("P1\n");
  printf("%d %d\n", x, y);
  /* 実際のデータ出力 */
  for (i = 0; i < y; i++) {
    for (j = 0; j < x; j++) {
      printf("%c ", pbm[i][j]);
    }
    printf("\n");
  }
}

/********************************************/
/* 画像データの読み込み                     */
/* x, y: 画像データの大きさ                 */
/********************************************/
char **pbm_read(int *x, int *y) {
  char **data;
  int i,j,x_size,y_size,d;
  /* この関数は未完成であり、問題2の完成対象である */
  if(getchar() != 'P' || getchar() != '1'){
    fprintf(stderr, "データの形式が違います\n");
    exit(1);
  }
  // printf("OK!\n");                                                                         
  scanf("%d",&x_size);   scanf("%d",&y_size);
  //printf("OK!%d %d\n",x_size,y_size);                                                       
  data = pbm_alloc(x_size, y_size);


 if(data == NULL) return NULL;

  // printf("OK\n");                                                                            

  for(i = 0; i < y_size; i++){
    for(j = 0; j < x_size; j++){
      if((d=scanf(" %c",&data[i][j])) != 1){
        pbm_free(data, x_size, y_size);
        //      printf("d=%d\n",d);                                                             
        return NULL;
      }


      if(data[i][j] != WHITE && data[i][j] != BLACK){
        pbm_free(data, x_size, y_size);
        return NULL;
      }
    }

    //    printf("for ok\n");                                                                   


  }

  *x = x_size;   *y = y_size;



  return data;
}



/********************************************/
/* 画像に正方形を描画                       */
/* pbm, x, y: 画像データの配列と大きさ      */
/* d: 正方形の半辺長                        */
/* col: 描画色 (BLACK ('1') or WHITE ('0')) */
/********************************************/
void   pbm_square(char **pbm, int x, int y, int d, char col) {
  /* この関数は未完成であり、問題2の完成対象である */
  int cx,cy,dx_1,dx_2,dy_1,dy_2,i;
  cx = x / 2;   cy = y /2;
  dx_1 = cx + d;   dx_2 = cx - d;
  dy_1 = cy + d;   dy_2 = cy - d;

  for(i = dx_2; i <= dx_1; i++){
    pbm[dy_1][i] = col;
    pbm[dy_2][i] = col;
  }

  for(i = dy_2; i <= dy_1; i++){
    pbm[i][dx_1] = col;
    pbm[i][dx_2] = col;
  }


}
