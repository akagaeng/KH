#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char sen1[1024] = {0,};
  char sen2[1024] = {0,};
  char arr1[1024] = {0,};
  char arr2[1024] = {0,};
  char yesno = 0;
  int i = 0, j = 0, cnt = 0;

  while (1) {
    fflush(stdin);
    printf("input 1st sentence: ");
    gets(sen1);

    printf("input 2nd sentence: ");
    gets(sen2);

    for (i = 0, j = 0; sen1[i] != '\0'; i++) {
      if ((sen1[i] >= 'A' && sen1[i] <= 'Z') ||
          (sen1[i] >= 'a' && sen1[i] <= 'z')) {
        arr1[j] = sen1[i];
        j++;
      }
    }

    for (i = 0, j = 0; sen2[i] != '\0'; i++) {
      if ((sen2[i] >= 'A' && sen2[i] <= 'Z') ||
          (sen2[i] >= 'a' && sen2[i] <= 'z')) {
        arr2[j] = sen2[i];
        j++;
      }
    }

    if (strlen(arr1) != strlen(arr2)) {
      printf("no anagram..\n");
    } else {
      for (i = 0, cnt = 0; i < strlen(arr1); i++) {
        for (j = 0; j < strlen(arr2); j++) {
          if (arr1[i] == arr2[j]) {
            arr1[i] = ' ';
            arr2[j] = ' ';
            cnt++;
            break;
          }
        }
      }

      if ((cnt == strlen(arr1)) && (cnt != 0)) {
        printf("YES! ANAGRAM!!\n");
      } else {
        printf("no anagram..\n");
      }
    }

    printf("continue? (y/n) : ");
    scanf("%c", &yesno);
    
    if (yesno == 'n') {
      printf("THANK YOU!!\n");
      break;
    }
  }
  return 0;
}