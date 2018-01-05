#include <stdio.h>

int main() {
  char arr[20][20] = {0,};
  int x = 0, y = 0, i = 0, j = 0, input = 0, num = 1, cnt = 0, x_sign = 1, y_sign = 1, flag = 1, cnt_x, cnt_y;
  
  printf("정수를 입력해주세요: ");
  scanf("%d", &input);
  
  cnt_x = input;
  cnt_y = input - 1;
  for (num = 1; num <= (input * input);) {
    for (i = 0; i < cnt_x; i++, num++) {
      x = x + x_sign;
      arr[y][x - 1] = num;
    }
    x_sign = -x_sign;
    cnt_x--;

    for (i = 0; i < cnt_y; i++, num++) {
      y = y + y_sign;
      arr[y][x - 1] = num;
    }
    y_sign = -y_sign;
    cnt_y--;
  }
  
  for (y = 0; y < input; y++) {
    for (x = 0; x < input; x++) {
      printf("%3d", arr[y][x]);
    }
    printf("\n");
  }
  return 0;
}