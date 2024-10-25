#include <stdio.h>

#define MAX (15)

int N;
int T[MAX];
int P[MAX];
int MAX_SUM = 0;

void solve(int day, int sum) {
  if (day > N)
    return;
  if (sum > MAX_SUM)
    MAX_SUM = sum;
  if (day == N)
    return;

  solve(day + T[day], sum + P[day]);
  solve(day + 1, sum);
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &T[i], &P[i]);
  }
  solve(0, 0);
  printf("%d\n", MAX_SUM);

  return 0;
}