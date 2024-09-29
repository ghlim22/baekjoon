#include <stdio.h>

int seq[20];

int main(void) {
  int N;
  int S;

  scanf("%d %d", &N, &S);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &seq[i]);
  }

  int cnt = 0;
  const int LIMIT = 1 << N;
  for (int i = 1; i < LIMIT; ++i) {
    int partial_sum = 0;
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        partial_sum += seq[j];
      }
    }
    if (partial_sum == S) {
      ++cnt;
    }
  }

  printf("%d", cnt);

  return 0;
}