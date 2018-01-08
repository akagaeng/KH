#include <stdio.h>

int main(int argc, char *argv[]) {
  char arr[21] = {0,};
  char arr2[10][4] = {0,};
  // arr2[][0]: 첫 번째 투구
  // arr2[][1]: 두 번째 투구
  // arr2[][2]: 세 번째 투구
  // arr2[][3]: 점수 합산
  // arr2[][4]: 보너스점수(스트라이크나 스페어처리시)
  char frame10 = 0; // 10프레임에서만 필요한 세번째 투구점수
  int i = 0, j = 0, cnt = 0;
  int sum = 0;
  int error_flag = 0; // 1인경우 에러임
  FILE *fp;
  fp = fopen("files/bowling.txt", "rt");
  printf("fp:%d\n", fp);

  for (i = 0; feof(fp) == 0; i++) { // while(fscanf(fp,"%d",&arr[i]) ==1 )
    fscanf(fp, "%d", &arr[i]);
    // printf("%d\n",arr[i]);
  }

  printf("\n입력된 내용\n");
  for (i = 0; i < 21; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (i = 0, j = 0; i < 21; i++) {
    if (j < 9) {
      if (arr[i] == 10) {
        arr2[j][0] = 10;
        arr2[j][1] = 0;
        j++;
      } else {
        arr2[j][0] = arr[i];
        i++;
        arr2[j][1] = arr[i];
        j++;
      }
    } else if (j == 9) { // 10프레임의 경우
      arr2[j][0] = arr[i];
      arr2[j][1] = arr[i + 1];
      frame10 = arr[i + 2];
      printf("i: %d j: %d\n", i, j);
      j++;
      break;
    }
    if (j > 9) {
      error_flag = 1;
      break;
    }
  }

  for (i = 0; i < 10;
       i++) { //프레임별 점수 합산, 10프레임은 개별합산. 및 에러 체크
    if (i < 9) {
      arr2[i][2] = arr2[i][0] + arr2[i][1];
      if (arr2[i][2] > 10) {
        error_flag = 1;
        break;
      } else if (arr2[i][0] == 10) {
        if (arr2[i + 1][0] == 10) { //다음 투구까지 스트라이크인 경우
          arr2[i][3] = arr2[i + 1][0] + arr2[i + 2][0];
        } else if (arr2[i + 1][0] != 10) { //다음투구는 스트라이크 아닌 경우
          arr2[i][3] = arr2[i + 1][0] + arr2[i + 1][1];
        }
      } //스트라이크인경우 다음2번투구 점수를 보너스로
      else if (arr2[i][2] == 10) {
        arr2[i][3] = arr2[i + 1][0];
      }      //스페어인 경우 다음 1번투구 점수를 보너스로
    } else { // 10프레임의 경우
      if (arr2[i][0] == 10) { //첫번째 투구가 스트라이크인 경우
        arr2[i][2] = arr2[i][0] + arr2[i][1] + frame10;
      } else if (arr2[i][1] == 10) { //두번째 투구가 스트라이크인 경우
        arr2[i][2] = arr2[i][0] + arr2[i][1] + frame10;
      } else if (arr2[i][0] + arr2[i][1] == 10) { //두번째 투구가 스페어인 경우
        arr2[i][2] = arr2[i][0] + arr2[i][1] + frame10;
      } else { //세번째 투구의 기회가 없는 경우
        arr2[i][2] = arr2[i][0] + arr2[i][1];
      }
    }
  }

  if (error_flag == 1) {
    printf("error\n");
  }
  printf("+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+\n");
  printf("|");
  for (i = 0; i < 10; i++) {
    if (i == 9) {
      printf(" %3d |", i + 1);
    } else {
      printf("%3d |", i + 1);
    }
  }
  printf("\n");
  printf("+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
  for (i = 0; i < 10; i++) {
    if (i < 9) {
      if (arr2[i][0] == 10) {
        printf("| x ");
      } else if (arr2[i][3] == 10) {
        printf("|%2d: /", arr2[i][0]);
      } else if (arr2[i][0] == 0) {
        printf("| -:%2d", arr2[i][1]);
      } else if (arr2[i][1] == 0) {
        printf("|%2d: -", arr2[i][0]);
      } else {
        printf("|%2d:%2d", arr2[i][0], arr2[i][1]);
      }
    } else { // i==9 (10프레임의 경우)
      printf("*%2d:%2d:%2d", arr2[9][0], arr2[9][1], frame10);
    }
  }
  printf("|");
  printf("\n");
  printf("+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
  for (i = 0; i < 10; i++) {
    printf("| %2d ", arr2[i][2]);
  }
  printf("|");
  printf("\n");
  printf("+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
  for (i = 0; i < 10; i++) {
    printf("| %2d ", arr2[i][3]);
  }
  printf("|");
  printf("\n");
  printf("+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
  printf("|");
  printf("\n");
  printf("+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+\n");
  sum = 0;
  for (i = 0; i < 10; i++) {
    sum = sum + (arr2[i][2] + arr2[i][3]);
    printf("| %2d ", sum);
  }
  printf("|");
  printf("\n");
  return 0;
}