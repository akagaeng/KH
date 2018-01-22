#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp1;
  FILE *fp2;
  int jan_go = 100000, juk_lip = 5000, pay = 0, pay_back = 0, use_juk_lip = 0;
  char ch = 0;

  fp1 = fopen("files/jango.txt", "w+b");
  fp2 = fopen("files/juklip.txt", "w+b");

  fprintf(fp1, "%d", jan_go);
  fprintf(fp2, "%d", juk_lip);
  
  while ((jan_go != 0)) {
    printf("현재 통장 잔고는 %d원이고, 적립금은 %d원 입니다.\n", jan_go, juk_lip);
    printf("구매하실 물건의 가격을 입력하세요: ");
    scanf("%d", &pay);
    getchar();
    if ((pay <= jan_go) && (pay >= 0) && (jan_go > 0)) {
      pay_back = pay * 0.05;
      printf("적립금을 사용하시겠습니까? (Y/N) : ");
      scanf("%c", &ch);
      switch (ch) {
 
      case 'y':
      case 'Y':
        while (1) {
          if (juk_lip == 0) {
            printf("적립금이 없습니다.\n");
            jan_go = jan_go - pay;
            break;
          } else {
            printf("현재 적립금은 %d원 있습니다.", juk_lip);
            printf("사용하실 적립금을 입력하세요: ");
            scanf("%d", &use_juk_lip);
            if ((use_juk_lip <= juk_lip) && (use_juk_lip >= 0) &&
                ((juk_lip - use_juk_lip) >= 0)) {
              jan_go = jan_go - pay + use_juk_lip;
              juk_lip = juk_lip - use_juk_lip;
              break;
            } else {
              printf("잘못 입력하셨습니다.\n");
            }
          } // end else
        }   // end while
        break;

      case 'n':
      case 'N':
        printf("%d원 적립되었습니다.\n", pay_back);
        juk_lip = juk_lip + pay_back;
        jan_go = jan_go - pay;
        break;
      } // end switch

      fclose(fp1);
      fclose(fp2);

      fp1 = fopen("files/jango.txt", "w+b");
      fp2 = fopen("files/juklip.txt", "w+b");

      fprintf(fp1, "%d", jan_go);
      fprintf(fp2, "%d", juk_lip);
      
      fclose(fp1);
      fclose(fp2);
    } // end if
    else {
      printf("잘못 입력하셨습니다.\n");
    } //구매할 물건의 가격(pay)이 부족, 음수입력, 잔고 부족
  } // end while
  printf("잔고가 0원입니다.프로그램을 종료합니다.\n");
  return 0;
}