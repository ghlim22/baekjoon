#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX (20)

int N;
int S[MAX][MAX];
int comb[MAX / 2];
int selected[MAX];
int answer = INT_MAX;

/*
[1..N-1] 명 선택
스타트 팀의 능력치 합 구하기

스타트에 선택되지 않은 사람들로 링크 팀의 능력치 합 구하기

두 팀의 능력치 차 구하기
정답 갱신
*/

void solve(int start, int len) {
  /* Caculate the total ability of each team */
  int start_ability = 0;
  int link_ability = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (selected[i] && selected[j])
        start_ability += S[i][j];
      if (!selected[i] && !selected[j])
        link_ability += S[i][j];
    }
  }
  int diff = abs(start_ability - link_ability);
  if (diff < answer) {
    answer = diff;
  }

  /* Each team consists of at least one person */
  if (len == N - 1) {
    return;
  }

  for (int i = start; i < N; ++i) {
    selected[i] = 1;
    solve(i + 1, len + 1);
    selected[i] = 0;
  }
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      scanf("%d", &S[i][j]);
    }
  }
  solve(0, 0);
  printf("%d", answer);
  return 0;
}