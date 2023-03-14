#include <stdio.h>

#define func(x)  ((x)*(x)-2*(x)-3)

int main()
{
  int a = 1;
  double b = 0.5;

  printf("a=%d, b=%f\n", a, b);
  printf("func(a) = %d\n", func(a));
  printf("func(a+2) = %d\n", func(a + 2));
  printf("func(a)*4 = %d\n", func(a) * 4);
  printf("func(b) = %f\n", func(b));
  printf("func(b+2.5) = %f\n", func(b + 2.5));

  return 0;
}