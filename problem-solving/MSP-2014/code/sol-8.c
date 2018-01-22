#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int answer = 0, input = 0, cnt = 1;
  int i = 0;
  srand(time(NULL));
  answer = rand() % 51;
  printf("answer: %d\n", answer);
  printf("숫자 맞추기 게임\n10번 안에 맞춰야 합니다.\n0~50사이의 수를 입력해주세요!\n");
  
  while (cnt <= 10) {
    printf("숫자 입력 (시도횟수 %d/10): ", cnt);
    scanf("%d", &input);
    
    if (input < 0 || input > 50) {
      printf("유효하지 않은 수입니다\n0~50 사이의 수를 다시 입력해주세요\n");
    } else {
      if (input > answer) {
        printf("down\n");
      } else if (input < answer) {
        printf("up\n");
      } else {
        printf("정답!\n");
        break;
      }
      cnt++;
    }
  }
  printf("\n정답을 맞추지 못했습니다.\nGAME OVER\n");

  return 0;
}