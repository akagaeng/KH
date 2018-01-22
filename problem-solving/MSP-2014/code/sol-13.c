#include <stdio.h>

void sosoo_func(int x) {
  int i = 0, cnt = 0;
  for (i = 1; i <= x; i++) {
    if (x % i == 0) {
      cnt++;
    }
  }
  if (cnt == 2) {
    printf("%d ", x);
  }
}

int main(int argc, char *argv[]) {
  int a = 0, b = 0, i = 0;
  printf("1~300 사이의 두 수를 입력하시오: ");
  scanf("%d %d", &a, &b);

  for (i = a; i <= b; i++) {
    sosoo_func(i);
  }
  printf("\n");
  return 0;
}