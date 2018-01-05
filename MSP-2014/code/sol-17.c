#include <stdio.h>
#include <time.h>

unsigned char x = 0, y = 0, z = 0;
char arr[4][4][2] = {0,}; //입력이 없는 경우에 빈칸이 되어야 하므로 문자형으로 입출력함
char num[6][2] = {
    {' ', '2'}, {' ', '4'}, {' ', '8'}, {'1', '6'}, {'3', '2'}, {'6', '4'},
}; // 2자리의 수를 문자형으로 표현하기 위해 2차원 배열에 각각 담음

void rand_assign(int _cnt) { // 입력 개수만큼 빈칸에 할당하는 함수
  int _i = 0;
  for (_i = 0;;) { // 빈칸에 4나 2 채우기
    x = rand() % 4;
    y = rand() % 4;
    z = rand() % 2; // rand%2 결과 0 or 1 => 0->'2', 1-> '4'

    if (arr[y][x][1] == 0) { //비어있는 곳에 채우기. 숫자가 있는 경우 
      arr[y][x][0] = num[z][0]; //뒷자리는 항상 차있으므로
      arr[y][x][1] = num[z][1]; // 1의자리인 arr[y][x][1]만 체크하면 됨
      _i++;
    }
    if (_i == _cnt) {
      break;
    } //숫자 2개 배치된 경우 배치 종료
  }
}

int main(int argc, char *argv[]) {
  char input = 0, temp = 0, cnt = 0;
  int i = 0, j = 0, k = 0, m = 0;
  srand(time(NULL));
  rand_assign(2);
  while (input != 'x') { // x를 누른 경우 종료됨
    printf("random y: %d x: %d z: %d\n", y, x, z);
    printf("+---------+---------+---------+---------+\n");
    printf("| | | | |\n"); //[0][0] [0][1]
                           //[0][2] [0][3]
    printf("|   %c%c |", arr[0][0][0], arr[0][0][1]);
    printf("   %c%c |", arr[0][1][0], arr[0][1][1]);
    printf("   %c%c |", arr[0][2][0], arr[0][2][1]);
    printf("   %c%c |\n", arr[0][3][0], arr[0][3][1]);
    printf("| || ||\n");
    printf("+---------+---------+---------+---------+\n");
    printf("|| | | |\n"); //[0][0] [0][1] [0][2]
                          //[0][3]
    printf("|   %c%c |", arr[1][0][0], arr[1][0][1]);
    printf("   %c%c |", arr[1][1][0], arr[1][1][1]);
    printf("   %c%c |", arr[1][2][0], arr[1][2][1]);
    printf("   %c%c |\n", arr[1][3][0], arr[1][3][1]);
    printf("| || ||\n");
    printf("+---------+---------+---------+---------+\n");
    printf("| | | | |\n"); //[0][0] [0][1]
                           //[0][2] [0][3]
    printf("|   %c%c |", arr[2][0][0], arr[2][0][1]);
    printf("   %c%c |", arr[2][1][0], arr[2][1][1]);
    printf("   %c%c |", arr[2][2][0], arr[2][2][1]);
    printf("   %c%c |\n", arr[2][3][0], arr[2][3][1]);
    printf("| | | | |\n");
    printf("+---------+---------+---------+---------+\n");
    printf("| | | | |\n"); //[0][0] [0][1]
                           //[0][2] [0][3]
    printf("|   %c%c |", arr[3][0][0], arr[3][0][1]);
    printf("   %c%c |", arr[3][1][0], arr[3][1][1]);
    printf("   %c%c |", arr[3][2][0], arr[3][2][1]);
    printf("   %c%c |\n", arr[3][3][0], arr[3][3][1]);
    printf("| | | | |\n");
    printf("+---------+---------+---------+---------+\n");

    for (i = 0, cnt = 0; i < 4; i++) { //남은 빈칸 수 체크
      for (j = 0; j < 4; j++) {
        if (arr[i][j][1] == 0) {
          cnt++;
        }
      }
    }
    printf("cnt: %d\n", cnt);
    if (cnt == 0) {
      printf("GAME OVER\n");
      break;
    }
    input = getch();
    printf("%c", input); //입력한 키값 출력(나중에 지우기)

    switch (input) { //대소문자 상관없이 w, a, d, s누를 경우에만 기능 구현
    case 'w': //위쪽 이동
    case 'W':
      //일단 위로 다 이동시킨 다음에 더하기 체크
      for (j = 0; j < 4 - 1; j++) {
        for (i = 0; i < 4; i++) {
          for (k = 0; k < 3; k++) {
            if (arr[j][i][1] == 0) { //뒷자리만 체크하면 됨.
              for (m = 0; j + m <= 2; m++) {
                arr[j + m][i][0] = arr[j + m + 1][i][0];
                arr[j + m][i][1] = arr[j + m + 1][i][1];
                arr[j + m + 1][i][0] = 0;
                arr[j + m + 1][i][1] = 0;
              }
            } // 4번째 칸에만 차있는 경우때문에 3번 체크해주어야 함
          }
        }
      }

      for (i = 0; i < 4; i++) { // 2개씩 비교하므로 맨 마지막은 비교하면 안됨.
        for (j = 0; j < 4 - 1; j++) {
          for (k = 0; k < 5; k++) {
            // num[6][]인 경우는 64(미션성공) 이므로 더할필요없으므로 체크x
            if (arr[j][i][0] == num[k][0] && arr[j][i][1] == num[k][1] &&
                arr[j + 1][i][0] == num[k][0] &&
                arr[j + 1][i][1] == num[k][1]) {
              arr[j][i][0] = num[k + 1][0];
              arr[j][i][1] = num[k + 1][1];
              for (m = 0; j + 1 + m <= 2; m++) {
                arr[j + 1 + m][i][0] = arr[j + 1 + m + 1][i][0];
                arr[j + 1 + m][i][1] = arr[j + 1 + m + 1][i][1];
                arr[j + 1 + m + 1][i][0] = 0;
                arr[j + 1 + m + 1][i][1] = 0;
              }
            }
          }
        }
      }
      rand_assign(1);
      break;

    case 'a': //왼쪽 이동 case 'A': //일단 전부 왼쪽으로 이동
      for (i = 0; i < 4 - 1; i++) {
        for (j = 0; j < 4; j++) {
          for (k = 0; k < 3; k++) {
            if (arr[j][i][1] == 0) { //뒷자리만 체크하면 됨.
              for (m = 0; i + m <= 2; m++) {
                arr[j][i + m][0] = arr[j][i + m + 1][0];
                arr[j][i + m][1] = arr[j][i + m + 1][1];
                arr[j][i + m + 1][0] = 0;
                arr[j][i + m + 1][1] = 0;
              }
            } // 4번째 칸에만 차있는 경우때문에 3번 체크해주어야 함
          }
        }
      }

      for (i = 0; i < 4 - 1; i++) {
        // 2개씩 비교하므로 맨 마지막은 비교하면 안됨
        for (j = 0; j < 4; j++) {
          for (k = 0; k < 5; k++) {
            // num[6][]인 경우는 64(미션성공)이므로 더할필요없으므로 체크x
            if (arr[j][i][0] == num[k][0] && arr[j][i][1] == num[k][1] &&
                arr[j][i + 1][0] == num[k][0] &&
                arr[j][i + 1][1] == num[k][1]) {
              arr[j][i][0] = num[k + 1][0];
              arr[j][i][1] = num[k + 1][1];
              for (m = 0; i + 1 + m <= 2; m++) {
                arr[j][i + 1 + m][0] = arr[j][i + 1 + m + 1][0];
                arr[j][i + 1 + m][1] = arr[j][i + 1 + m + 1][1];
                arr[j][i + 1 + m + 1][0] = 0;
                arr[j][i + 1 + m + 1][1] = 0;
              }
            }
          }
        }
      }
      rand_assign(1);
      break;

    case 'd': //오른쪽 이동 case 'D': //일단 전부 오른쪽으로 이동
      for (i = 3; i > 0; i--) {
        for (j = 0; j < 4; j++) {
          for (k = 0; k < 3; k++) {
            if (arr[j][i][1] == 0) { //뒷자리만 체크하면 됨.
              for (m = 0; i - m >= 1; m++) {
                arr[j][i - m][0] = arr[j][i - m - 1][0];
                arr[j][i - m][1] = arr[j][i - m - 1][1];
                arr[j][i - m - 1][0] = 0;
                arr[j][i - m - 1][1] = 0;
              }
            } // 4번째 칸에만 차있는 경우때문에 3번 체크해주어야 함
          }
        }
      }
      
      for (i = 3; i > 0; i--) {
        // 2개씩 비교하므로 맨 마지막은 비교하면 안됨.
        for (j = 0; j < 4; j++) {
          for (k = 0; k < 5; k++) { // num[6][]인 경우는 64(미션성공)이므로
                                    // 더할필요없으므로 체크x
            if (arr[j][i][0] == num[k][0] && arr[j][i][1] == num[k][1] &&
                arr[j][i - 1][0] == num[k][0] &&
                arr[j][i - 1][1] == num[k][1]) {
              arr[j][i][0] = num[k + 1][0];
              arr[j][i][1] = num[k + 1][1];
              for (m = 0; i - 1 - m >= 1; m++) {
                arr[j][i - 1 - m][0] = arr[j][i - 1 - m - 1][0];
                arr[j][i - 1 - m][1] = arr[j][i - 1 - m - 1][1];
                arr[j][i - 1 - m - 1][0] = 0;
                arr[j][i - 1 - m - 1][1] = 0;
              }
            }
          }
        }
      }
      rand_assign(1);
      break;

    case 's': //아래쪽 이동 case 'S': //일단 전부 아래쪽으로 이동
      for (i = 0; i < 4; i++) {
        for (j = 3; j > 0; j--) {
          for (k = 0; k < 3; k++) {
            if (arr[j][i][1] == 0) { //뒷자리만 체크하면 됨.
              for (m = 0; j - m >= 1; m++) {
                arr[j - m][i][0] = arr[j - m - 1][i][0];
                arr[j - m][i][1] = arr[j - m - 1][i][1];
                arr[j - m - 1][i][0] = 0;
                arr[j - m - 1][i][1] = 0;
              }
            } // 4번째 칸에만 차있는 경우때문에 3번 체크해주어야 함
          }
        }
      }
      for (i = 0; i < 4; i++) { // 2개씩 비교하므로 맨 마지막은 비교하면 안됨
        for (j = 3; j > 0; j--) {
          for (k = 0; k < 5; k++) { // num[6][]인 경우는 64(미션성공)이므로
                                    // 더할필요없으므로 체크x
            if (arr[j][i][0] == num[k][0] && arr[j][i][1] == num[k][1] &&
                arr[j - 1][i][0] == num[k][0] &&
                arr[j - 1][i][1] == num[k][1]) {
              arr[j][i][0] = num[k + 1][0];
              arr[j][i][1] = num[k + 1][1];
              for (m = 0; j - 1 - m >= 1; m++) {
                arr[j - 1 - m][i][0] = arr[j - 1 - m - 1][i][0];
                arr[j - 1 - m][i][1] = arr[j - 1 - m - 1][i][1];
                arr[j - 1 - m - 1][i][0] = 0;
                arr[j - 1 - m - 1][i][1] = 0;
              }
            }
          }
        }
      }
      rand_assign(1);
      break;

    default:
      break;
    }
    system("cls");
  }
  return 0;
}