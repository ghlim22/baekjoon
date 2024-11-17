#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

int operate(int lhs, int rhs, char op) {
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

int main(void) {
  int n;
  int answer = INT32_MIN;
  bool priority[9];
  std::vector<int> operands;
  std::vector<char> operators;
  std::string expr;

  std::cin >> n;
  std::cin >> expr;
  for (char c : expr) {
    if (std::isdigit(c))
      operands.push_back(c - '0');
    else
      operators.push_back(c);
  }

  /*
  Bruteforce
  괄호를 선택하는 모든 경우의 수를 살펴본다.
  괄호가 중첩될 수 없음에 유의한다.
  괄호로 묶인 부분을 먼저 계산하고, 나머지를 이후에 계산한다.
  */

  const int OP_CNT = (n - 1) / 2;
  const int LIMIT = 1 << OP_CNT;
  for (int i = 0; i < LIMIT; ++i) {
    bool flag = false;
    std::memset(priority, 0, sizeof(priority));
    for (int j = 0; j < OP_CNT && !flag; ++j) {
      if (i & (1 << j)) {
        priority[j] = true;
        if (j > 0 && priority[j - 1])
          flag = true;
      }
    }
    if (flag)
      continue;

    std::vector<int> tmp = operands;
    std::vector<bool> empty(tmp.size(), false);
    for (int j = 0; j < OP_CNT; ++j) {
      if (priority[j]) {
        int lhs_idx = j;
        int rhs_idx = j + 1;
        while (rhs_idx < empty.size() && empty[rhs_idx]) {
          rhs_idx++;
        }
        tmp[rhs_idx] = operate(tmp[lhs_idx], tmp[rhs_idx], operators[j]);
        empty[lhs_idx] = true;
      }
    }
    for (int j = 0; j < OP_CNT; ++j) {
      if (!priority[j]) {
        int lhs_idx = j;
        int rhs_idx = j + 1;
        while (rhs_idx < empty.size() && empty[rhs_idx]) {
          rhs_idx++;
        }
        tmp[rhs_idx] = operate(tmp[lhs_idx], tmp[rhs_idx], operators[j]);
        empty[lhs_idx] = true;
      }
    }

    answer = std::max(answer, tmp.back());
  }

  std::cout << answer;

  return 0;
}