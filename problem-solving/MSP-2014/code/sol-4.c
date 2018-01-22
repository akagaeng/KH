#include <stdio.h>

int main() {
  char num[5] = {0,};
  int temp = 0, i = 0, j = 0, max = 0, min = 0;

  printf("수 입력: ");
  scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]);
  
  max = num[0];
  min = num[0];
  
  for (i = 1; i < 5; i++) {
    if (min >= num[i]) {
      min = num[i];
    }
    if (max <= num[i]) {
      max = num[i];
    }
  }
  printf("MAX: %d\nMIN: %d\n", max, min);
  return 0;
}