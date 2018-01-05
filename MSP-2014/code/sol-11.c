#include <stdio.h>

int main(int argc, char *argv[]) {
  int input = 0;
  int c500 = 0, c100 = 0, c50 = 0, c10 = 0;

  printf("거스름돈을 입력하세요: ");
  scanf("%d", &input);

  if (input < 0) {
    input = -input;
    printf("음수를 입력하셨습니다.\n양수인 %d원으로 계산합니다.\n", input);
  }

  c500 = input / 500;
  input = input - 500 * c500;
  c100 = input / 100;
  input = input - 100 * c100;
  c50 = input / 50;
  input = input - 50 * c50;
  c10 = input / 10;

  printf("거스름돈(동전수)\n");
  printf("500원 동전: %d개\n", c500);
  printf("100원 동전: %d개\n", c100);
  printf(" 50원 동전: %d개\n", c50);
  printf(" 10원 동전: %d개\n", c10);
  
  return 0;
}