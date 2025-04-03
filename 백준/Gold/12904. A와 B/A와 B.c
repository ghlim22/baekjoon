#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[1001];
char T[1001];

int main(void) {
  /* input */
  scanf("%s", S);
  scanf("%s", T);

  int slen = strlen(S);
  int tlen = strlen(T);

  for (int i = tlen - 1; i >= slen; --i) {
    if (T[i] == 'A') {
      T[i] = '\0';
    } else {
      /* reverse T[0..i-1] */
      T[i] = '\0';
      int len = strlen(T);
      int lmt = len / 2;
      for (int j = 0; j < lmt; ++j) {
        char tmp = T[j];
        T[j] = T[len - 1 - j];
        T[len - 1 - j] = tmp;
      }
    }
  }

  if (0 == strcmp(S, T)) {
    printf("%d\n", 1);
  } else {
    printf("%d\n", 0);
  }

  return 0;
}