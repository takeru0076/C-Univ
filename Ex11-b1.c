#include <stdio.h>
#include <math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_3(double, Point *);
void  rotate_4(double, Point *);

int main()
{
  double rad, deg;
  Point b1[2], b2[3], c;         /* 結果を入れる構造体 */

  b1[0].x = 1.0;
  b1[0].y = 0.0;
  b1[1].x = 3.0;
  b1[1].y = 2.0;

  b2[0].x = 1.0;
  b2[0].y = 0.0;
  b2[1].x = 3.0;
  b2[1].y = 2.0;



  printf("回転角 [度] を入力してください\n");
  scanf("%lf", &deg);
  rad = deg*M_PI/180;
  printf("回転角 %f [deg] (%f [rad])\n", deg, rad);

  /*                                                                                                                                                                                                        
   * ここに関数呼び出しおよび関連するコードを書く                                                                                                                                                           
   */
  c = rotate_3(rad,b1);
  rotate_4(rad,b2);

  printf("Center  : %f %f\n", b1[0].x, b1[0].y);
  printf("Point A : %f %f\n", b1[1].x, b1[1].y);
  printf("rotate_1 : %f %f\n", c.x, c.y);   /* 関数１の結果を出力 */
  printf("rotate_2 : %f %f\n", b2[2].x, b2[2].y);   /* 関数２の結果を出力 */
  return 0;
}

/*                                                                                                                                                                                                          
 * ここにプロトタイプに合わせた rotate_1関数の中身を書く                                                                                                                                                    
 */
Point rotate_3(double z, Point *b1){
    Point a,b_1;

    a.x = b1[1].x - b1[0].x;
    a.y = b1[1].y - b1[0].y;

    b_1.x = a.x;
    a.x = a.x * cos(z) - a.y * sin(z);
    a.y = b_1.x * sin(z) + a.y * cos(z);

    a.x += b1[0].x;
    a.y += b1[0].y;

    return a;
}

/*                                                                                                                                                                                                          
 * ここにプロトタイプに合わせた rotate_2関数の中身を書く                                                                                                                                                    
 */

void  rotate_4(double z, Point *b2){
  Point b_2;
    b2[2].x = b2[1].x - b2[0].x;
    b2[2].y = b2[1].y - b2[0].y;

    b_2.x = b2[2].x;
    b2[2].x = b2[2].x * cos(z) - b2[2].y * sin(z);
    b2[2].y = b_2.x * sin(z) + b2[2].y * cos(z);

    b2[2].x += b2[0].x;
    b2[2].y += b2[0].y;

}
