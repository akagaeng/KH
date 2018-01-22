#include <stdio.h>

int main() {
  char arr[1024] = {0,};
  int i = 0, flag = 0, cnt1 = 0, cnt2 = 0;

  while (flag != 1) {
    printf("괄호를 입력해주세요: ");
    scanf("%s", &arr);

    for (i = 0; arr[i] != '\0'; i++) {
      if (arr[i] != '(' && arr[i] != ')') {
        printf("잘못입력하셨습니다. ( or ) 만 입력해주세요. \n");
        flag = 0;
        break;
      } else {
        flag = 1;
      }
    } // end for
  }   // end while

  for (i = 0; arr[i] != '\0' && flag != 0; i++) {
    if (arr[i] == '(') {
      cnt1++;
    } else if (arr[i] == ')') {
      cnt2++;
    } else {
    }
    if (cnt1 - cnt2 < 0) {
      printf("NO");
      break;
    }
  }
  
  if ((cnt1 - cnt2) == 0) {
    printf("YES");
  } else {
    printf("NO");
  } // printf("cnt1: %d, cnt2: %d\n",cnt1,cnt2);
  return 0;
}