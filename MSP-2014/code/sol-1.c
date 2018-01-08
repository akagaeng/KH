#include <stdio.h>

int main() {
  int i = 0, j = 0;
  int dan = 0;

  while (1) {
    printf("출력할 단을 입력해주세요: ");
    scanf("%d", &dan);

    if (dan >= 1 && dan <= 9) {
      printf("1~9입니다.\n");
      break;
    } else {
      printf("1~9 사이의 숫자를 입력해주세요.\n");
    }
  }

  for (i = 1; i <= 9; i++) {
    // printf("%d x %d = %d\n",dan, i, dan * i);
    for (j = 1; j <= (dan * i); j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}