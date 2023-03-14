#include <stdio.h>

double subave_arr(double *);   /* プロトタイプ宣言 */

int main()
{
  double a[3], ave;

  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);

  ave = subave_arr(a);   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("平均差し引き後のデータ:  %+.3f  %+.3f  %+.3f\n", a[0], a[1], a[2]);
  return 0;
}

/* 平均を計算して各データから引き算する関数。戻り値はその平均値。 */
double subave_arr(double *x)
{
    int i;
    double ave=0;
    for(i = 0; i < 3; i++){
        ave += x[i];
    }
    ave /= 3;

    for(i = 0; i < 3; i++){
        x[i] -=ave;
    }

    return ave;
}