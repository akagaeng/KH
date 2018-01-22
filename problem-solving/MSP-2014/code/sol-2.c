#include <stdio.h>

int main() {
  char arr[] = "CodeChallenge2014withMSP";
  int i = 0;

  for (i = 0; arr[i] != '\0'; i++) {
    // 소문자
    if (arr[i] >= 'a' && arr[i] <= 'z') {
      printf("%c", arr[i] + ('A' - 'a'));
    }
    // 대문자
    else if (arr[i] >= 'A' && arr[i] <= 'Z') {
      printf("%c", arr[i] - ('A' - 'a'));
    }
    // 숫자
    else if (arr[i] >= '0' && arr[i] <= '9') {
      printf("%c", arr[i]);
    }
    // 기타
    else {
    }
  }
  printf("\n");

  return 0;
}
