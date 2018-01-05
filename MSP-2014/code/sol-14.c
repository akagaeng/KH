#include <stdio.h>

void num_func(int x) {
  switch (x) {
  case 1:
    printf("one");
    break;
  case 2:
    printf("two");
    break;
  case 3:
    printf("three");
    break;
  case 4:
    printf("four");
    break;
  case 5:
    printf("five");
    break;
  case 6:
    printf("six");
    break;
  case 7:
    printf("seven");
    break;
  case 8:
    printf("eight");
    break;
  case 9:
    printf("nine");
    break;
  default:
    printf("");
  } // end switch-case
} // end num_func

void nineteen_under_func(int x) {
  switch (x) {
  case 1:
    num_func(x);
    break;
  case 2:
    num_func(x);
    break;
  case 3:
    num_func(x);
    break;
  case 4:
    num_func(x);
    break;
  case 5:
    num_func(x);
    break;
  case 6:
    num_func(x);
    break;
  case 7:
    num_func(x);
    break;
  case 8:
    num_func(x);
    break;
  case 9:
    num_func(x);
    break;
  case 10:
    printf("ten");
    break;
  case 11:
    printf("eleven");
    break;
  case 12:
    printf("twelve");
    break;
  case 13:
    printf("thirteen");
    break;
  case 14:
    printf("fourteen");
    break;
  case 15:
    printf("fifteen");
    break;
  case 16:
    printf("sixteen");
    break;
  case 17:
    printf("seventeen");
    break;
  case 18:
    printf("eighteen");
    break;
  case 19:
    printf("nineteen");
    break;
  }
}
void tenth_func(int x) {
  switch (x) {
  case 2:
    printf("twenty");
    break;
  case 3:
    printf("thirty");
    break;
  case 4:
    printf("fourty");
    break;
  case 5:
    printf("fifty");
    break;
  case 6:
    printf("sixty");
    break;
  case 7:
    printf("seventy");
    break;
  case 8:
    printf("eighty");
    break;
  case 9:
    printf("ninety");
    break;
  }
}

/*
  예외 처리할 사항
  0~9
  10: ten
  11: eleven
  12: twelve
  13: thirteen
  14: fourteen
  15: fifteen
  16: sixteen
  17: seventeen
  18: eighteen
  19: nineteen
  20: twenty~29는 뒤에 one... 붙이면 됨
  30: thirty
  40: fourty
  50: fifty
  60: sixty
  70: seventy
  80: eighty
  90: ninety
*/

int main(int argc, char *argv[]) {
  int num = 0;
  int a = 0, b = 0, c = 0, d = 0;
  int i = 0;
  for (i = 1000; i < 1100; i++) {
    num = i;

    printf("숫자를 입력하시오"); //
    scanf("%d", &num);
    a = num / 1000;         //천의 자리
    b = (num % 1000) / 100; //백의자리
    c = (num % 100) / 10;   //십의자리
    d = num % 10;           //일의자리
    // printf("num: %d, a=%d, b=%d, c=%d, d=%d\n", num, a, b, c, d); //
    // printf("[%4d]: ", i);

    if (num == 0) {
      printf("zero");
    } else if ((num > 9999) || (num < 0)) {
      printf("Out of Range!\n");
    } else {
      // 1000단위
      if (a != 0) {
        num_func(num / 1000);
        printf("thousand");
        num = num % 1000;
      }
      // 100단위
      if (b != 0) {
        num_func(num / 100);
        printf("hundred");
        num = num % 100;
      }
      // 10단위
      // 1~19까지
      if ((num) >= 0 && (num) <= 19) {
        nineteen_under_func(num);
      } else if ((num / 10) >= 2 && (num / 10) <= 9) { //십의자리 예외 포함시킨것.
        tenth_func(num / 10);       // 10의자리 처리
        num_func(num % 10);         // 1의자리 처리
      }
    }
    printf("\n");
  }
  return 0;
}