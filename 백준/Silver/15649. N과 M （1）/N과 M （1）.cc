#include <stdio.h>

#define MAX (8)

int seq[MAX];
int visited[MAX + 1];
int n;
int m;

void comb(int cur, int len) {
  seq[len - 1] = cur;
  visited[cur] = 1;
  if (len == m) {
    for (int i = 0; i < len; ++i) {
      printf("%d ", seq[i]);
    }
    printf("\n");
    visited[cur] = 0;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (visited[i])
      continue;
    comb(i, len + 1);
  }
  visited[cur] = 0;
}

int main(void) {

  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    comb(i, 1);
  }

  return 0;
}