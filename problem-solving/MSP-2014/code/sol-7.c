#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp1;
  FILE *fp2;
  char buf1[1024] = {0,};
  char buf2[1024] = {0,};
  char mytb[6][5] = {0,};
  char frtb[6][5] = {0,};

  char weekday[10] = "월화수목금";
  int i = 0, j = 0, k = 0;

  fp1 = fopen("files/mytime.txt", "r");
  fp2 = fopen("files/friendtime.txt", "r");

  while (feof(fp1) == 0) {
    fgets(buf1, sizeof(buf1), fp1);
  } //파일 내용 불러오기
  while (feof(fp2) == 0) {
    fgets(buf2, sizeof(buf2), fp2);
  } //파일 내용 불러오기
  for (i = 0, j = 0, k = 0; i < strlen(buf1);
       i++) { //내 시간표 2차원 배열에 나눠 담기
    if (buf1[i] == 'o' || buf1[i] == '-') {
      mytb[j][k] = buf1[i];

      if (k == 4) {
        k = 0;
        j++;
      } else {
        k++;
      }
    }
  }
  for (i = 0, j = 0, k = 0; i < strlen(buf2); i++) { //친구 시간표 2차원 배열에 나눠 담기
    if (buf2[i] == 'o' || buf2[i] == '-') {
      frtb[j][k] = buf2[i];

      if (k == 4) {
        k = 0;
        j++;
      } else {
        k++;
      }
    }
  }

  printf("[겹치는 공강 찾아주는 프로그램]\n");
  printf("c.f. 공강은 \"-\"로 수업은 \"o\"로 표시됩니다!\n\n");
  printf("<My TimeTable>\n");
  printf("\tMON\tTUE\tWED\tTHU\tFRI\n");

  for (j = 0; j < 6; j++) { // 내 시간표 출력
    printf("%d\t", j + 1);
    for (k = 0; k < 5; k++) {
      printf("%c\t", mytb[j][k]);
    }
    printf("\n");
  }
  printf("\n");

  printf("<Friend's TimeTable>\n");
  printf("\tMON\tTUE\tWED\tTHU\tFRI\n");
  
  for (j = 0; j < 6; j++) { //친구 시간표 출력
    printf("%d\t", j + 1);
    for (k = 0; k < 5; k++) {
      printf("%c\t", frtb[j][k]);
    }
    printf("\n");
  }
  printf("\n");

  printf("<겹치는 공강>\n");

  for (k = 0; k < 5; k++) {
    for (j = 0; j < 6; j++) {
      if ((mytb[j][k] == '-') && (frtb[j][k] == '-')) { //둘다 공강인 경우 체크
        printf("%c%c요일 %d교시\n", weekday[k * 2], weekday[k * 2 + 1], j + 1); //한글은 %c%c두개 문자 합쳐서 출력됨.
      }
    }
  }
  return 0;
}