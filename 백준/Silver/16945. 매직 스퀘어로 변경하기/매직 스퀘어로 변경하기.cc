#include <algorithm>
#include <climits>
#include <iostream>

int A[3][3];
int B[3][3];
int ANSWER = INT_MAX;
bool USED[10];

bool check(void) {
  for (int i = 0; i < 3; ++i) {
    int row = 0;
    int col = 0;
    for (int j = 0; j < 3; ++j) {
      row += B[i][j];
      col += B[j][i];
    }
    if (row != 15 || col != 15) {
      return false;
    }
  }
  if (B[0][0] + B[1][1] + B[2][2] != 15)
	return false;
  if (B[0][2] + B[1][1] + B[2][0] != 15)
	return false;
 
  return true;
}

int cal_cost(void) {
  int cost = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cost += std::abs(A[i][j] - B[i][j]);
    }
  }
  return cost;
}

void dfs(int depth) {
  if (depth == 9) {
    if (check()) {
      ANSWER = std::min(ANSWER, cal_cost());
    }
    return;
  }

  for (int i = 1; i <= 9; ++i) {
    if (USED[i])
      continue;
    USED[i] = true;
    B[depth / 3][depth % 3] = i;
    dfs(depth + 1);
    USED[i] = false;
  }
}

int main(void) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cin >> A[i][j];
    }
  }
  dfs(0);
  std::cout << ANSWER;

  return 0;
}