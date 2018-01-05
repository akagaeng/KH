#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memset
#include <time.h>

int main() {
  int i = 0, j = 0, number = 0; // number: 입력받을 구슬의 갯수
  int input1 = 0, input2 = 0;
  char rand_num = 0;
  char temp[100][2] = {0,};
  char flag[100] = {0,};
  char turn[100] = {0,}; // 1-2-5-4-3 or 1-5-4-2-3 or ....
  char color_cnt[26] = {0,}; // color_cnt[0]= a, [1]=b [2]=c ... 각 숫자의 갯수 셈
  char reverse[26] = {0,};
  char swap_temp = 0;
  char cnt = 0;

  srand(time(NULL));

  while (1) {
    while (1) {
      printf("there are 26(a~z) colors to be chosen\n");
      printf("insert the number of beads (5~100): ");
      scanf("%d", &number);
      if (number >= 5 && number <= 100) {
        break;
      } else {
        printf("wrong number\ninput again\n\n");
      }
    }

    memset(flag, 1, number); //입력된 갯수만큼 flag를 1로 바꾸어줌

    // for (i = 0; i < 100; i++) {
    //   printf("flag[%d]: %d\n", i, flag[i]);
    // }

    printf("you chose %d beads\n", number);
    printf("Insert 2 colors each (ex: --> 1. b c )\n");

    for (i = 0; i < number; i++) {
      printf("-> %d : ", i + 1);
      fflush(stdin); //버퍼에 입력된 엔터값을 지움.
      scanf("%c%c", &input1, &input2);
      // printf("%c %c", input1, input2);

      color_cnt[input1 - 'a']++;
      color_cnt[input2 - 'a']++;

      temp[i][0] = input1;
      temp[i][1] = input2;
    } // temp[0]~temp[99] 사이에 비즈 구성 넣기 완료

    //비즈가 모양이 만들어지는지 체크
    for (i = 0; i < 26; i++) {
      printf("%c: %d\n", i + 'a', color_cnt[i]);
    }

    for (i = 0; i < 26; i++) {
      if (color_cnt[i] % 2 == 1) {
        printf("failed!!\n");
        break;
      }
    }

    printf("OK!\n"); // failed가 되지 않으면 성공. 비즈 모양 만들어질 환경 OK

    //비즈모양 맞추기.
    //순번 정하기
    for (i = 0; i < number; i++) {
      if (i == 0) {
        printf("[%c %c]", temp[i][0], temp[i][1]);
        cnt++;
      }

      for (j = 1; j < number; j++) {
        if (temp[i][1] == temp[j][0] && flag[j] == 1) { // 순서대로인 경우
          flag[j] = 0;
          printf("-[%c%c]", temp[j][0], temp[j][1]);
          break;
        } else if (temp[i][1] == temp[j][1] &&
                   flag[j] == 1) { //순서가 거꾸로인 경우
          flag[j] = 0;
          // reverse[i]=1;
          fflush(stdin);
          swap_temp = temp[j][1];
          temp[j][1] = temp[j][0];
          temp[j][0] = swap_temp;
          printf("-#[%c %c]#", temp[j][0], temp[j][1]);
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}