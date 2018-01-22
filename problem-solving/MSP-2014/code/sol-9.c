#include <math.h>
#include <stdio.h>

char arr[10];
int n = 0, k = 0;

void binary(int i) {
  int a;
  for (a = 0; a < n; a++) {
    if (i & (1 << a)) {
      arr[a] = 1;
    } else {
      arr[a] = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  int i = 0, j = 0, cnt = 0, x = 0;
  while (1) {
    printf("n을 입력해주세요: ");
    scanf("%d", &n);
    if (n >= 0 && n <= 10) {
      break;
    } else {
      printf("0~10 사이의 숫자를 입력해주세요.\n");
    }
  }
  while (1) {
    printf("k을 입력해주세요: ");
    scanf("%d", &k);
    if (k >= 0 && k <= 10) {
      break;
    } else {
      printf("0~10 사이의 숫자를 입력해주세요.\n");
    }
  }

  x = pow(2, n);

  for (i = 0; i < x; i++) {
    binary(i);
    cnt = 0;
    for (j = 0; j < n; j++) {
      if (arr[j] == 1) {
        cnt++;
      }
    }
    
    if (cnt == k) {
      for (j = n - 1; j >= 0; j--) {
        printf("%d", arr[j]);
      }
      printf("\n");
    }
  }
  return 0;
}