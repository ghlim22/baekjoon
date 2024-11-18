#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>

int N;
std::string EXPR;
int ANSWER = INT_MIN;

int cal(int lhs, int rhs, char op) {
  switch (op) {
  case '+':
    return lhs + rhs;
  case '-':
    return lhs - rhs;
  case '*':
    return lhs * rhs;
  default:
    assert(false);
  }
}

void solve(int sum, int cur) {
  if (cur >= N) {
    ANSWER = std::max(ANSWER, sum);
    return;
  }

  char op = (cur == 0) ? '+' : EXPR[cur - 1];

  if (cur + 2 < N) {
    int next = cal(EXPR[cur] - '0', EXPR[cur + 2] - '0', EXPR[cur + 1]);
    solve(cal(sum, next, op), cur + 4);
  }

  solve(cal(sum, EXPR[cur] - '0', op), cur + 2);
}

int main(void) {
  std::cin >> N;
  std::cin >> EXPR;

  solve(0, 0);

  std::cout << ANSWER;

  return 0;
}