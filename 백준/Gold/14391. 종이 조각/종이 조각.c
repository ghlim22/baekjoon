#include <stdio.h>
#include <string.h>

#define MAX (4)

int g_board[MAX][MAX];
int g_visited[MAX][MAX];
int g_max_score = 0;
int N;
int M;

void input(void) {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%1d", &g_board[i][j]);
    }
  }
}

int is_valid(int r, int c) {
  if (!(r >= 0 && r < N))
    return 0;
  if (!(c >= 0 && c < M))
    return 0;
  return !g_visited[r][c];
}

int is_vertical(int r, int c, int status) {
  return status & (1 << (r * M + c));
}

int add_h(int r, int c, const int STATUS) {
  int score = 0;
  while (is_valid(r, c) && !is_vertical(r, c, STATUS)) {
    score *= 10;
    score += g_board[r][c];
    g_visited[r][c] = 1;
    ++c;
  }
  return score;
}

int add_v(int r, int c, const int STATUS) {
  int score = 0;
  while (is_valid(r, c) && is_vertical(r, c, STATUS)) {
    score *= 10;
    score += g_board[r][c];
    g_visited[r][c] = 1;
    ++r;
  }
  return score;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int add_up_scores(const int STATUS) {
  int score = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (g_visited[i][j])
        continue;
      if (is_vertical(i, j, STATUS)) { /* Vertically sliced piece */
        score += add_v(i, j, STATUS);
      } else { /* Horizontally sliced piece */
        score += add_h(i, j, STATUS);
      }
    }
  }

  return score;
}

void solve(void) {
  const int LIMIT = 1 << (N * M);
  for (int i = 0; i < LIMIT; ++i) {
    memset(g_visited, 0, sizeof(g_visited));
    g_max_score = max(g_max_score, add_up_scores(i));
  }
  printf("%d", g_max_score);
}

int main(void) {
  input();
  solve();

  return 0;
}