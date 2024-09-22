#include <stdio.h>

#define MAX (8)

int seq[MAX];
int n;
int m;

void comb(int cur, int len) {
  seq[len - 1] = cur;
  if (len == m) {
    for (int i = 0; i < len; ++i) {
      printf("%d ", seq[i]);
    }
    printf("\n");
    return;
  }

  for (int i = cur; i <= n; ++i) {
    comb(i, len + 1);
  }
}

int main(void) {

  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    comb(i, 1);
  }

  return 0;
}