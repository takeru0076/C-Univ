#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_1(double, Point, Point);
void  rotate_2(double, Point *, Point *);

int main()
{
  double rad, deg;
  Point c = {1.0, 0.0}, a = {3.0, 2.0}; /* 中心と回転対象の点 */
  Point b1, b2;         /* 結果を入れる構造体 */

  printf("回転角 [度] を入力してください\n");
  scanf("%lf", &deg);
  rad = deg*M_PI/180;
  printf("回転角 %f [deg] (%f [rad])\n", deg, rad);
  
  /*
   * ここに関数呼び出しおよび関連するコードを書く
   */
  b1 = rotate_1(rad,c,a);
  b2 = a;
  rotate_2(rad,&c,&b2);

  printf("Center  : %f %f\n", c.x, c.y);
  printf("Point A : %f %f\n", a.x, a.y);
  printf("rotate_1 : %f %f\n", b1.x, b1.y);   /* 関数１の結果を出力 */
  printf("rotate_2 : %f %f\n", b2.x, b2.y);   /* 関数２の結果を出力 */
  return 0;
}

/*
 * ここにプロトタイプに合わせた rotate_1関数の中身を書く
 */
Point rotate_1(double z, Point c, Point a){
    Point b1,b_1;

    b1.x = a.x - c.x;
    b1.y = a.y - c.y;

    b_1.x = b1.x;
    b1.x = b1.x * cos(z) - b1.y * sin(z);
    b1.y = b_1.x * sin(z) + b1.y * cos(z);

    b1.x += c.x;
    b1.y += c.y;

    return b1;
}

/*
 * ここにプロトタイプに合わせた rotate_2関数の中身を書く
 */

void  rotate_2(double z, Point *c, Point *b2){
  Point b_2;
    b2->x = b2->x - c->x;
    b2->y = b2->y - c->y;

    b_2.x = b2->x;
    b2->x = b2->x * cos(z) - b2->y * sin(z);
    b2->y = b_2.x * sin(z) + b2->y * cos(z);
    
    b2->x += c->x;
    b2->y += c->y;

}