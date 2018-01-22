#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i = 0, j = 0, cnt = 0;
  int input = 0;

  FILE *fp;
  char str[10][1024] = {0,};

  printf("MSP 노래방에 오신 것을 환영합니다!\n\n");
  printf("번호\t가수 - 노래 제목\n");

  fp = fopen("files/karaoke.txt", "r");

  for (i = 0; feof(fp) == 0; i++) {
    fgets(str[i], sizeof(str[i]), fp);
  }
  cnt = i;

  fclose(fp);

  for (i = 0; i < cnt; i++) {
    for (j = 0; str[i][j] != '\t'; j++) {
      printf("%c", str[i][j]);
    }
    printf("\n");
  }

  while (1) {
    printf("\n\n(0번을 누르면 노래방 프로그램이 종료됩니다.)\n");
    printf("노래 번호를 입력해주세요 :");
    scanf("%d", &input);

    if (input >= 1 && input <= cnt) { //번호에 있는 숫자 누른 경우
      for (i = input - 1, j = 0; str[i][j] != '\t'; j++) {
      } //탭있는곳까지 위치 구함
      for (i = input - 1; str[i][j] != '\0'; j++) { //탭 있는곳부터 출력
        printf("%c", str[i][j + 1]);
      }
      printf("\n");
    } else if (input == 0) {
      printf("프로그램을 종료합니다.\n");
      exit(0);
    } // 0번 누른 경우 프로그램 종료
    else {
      printf("잘못 누르셨습니다.\n");
    }
  }
  return 0;
}