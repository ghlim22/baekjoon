#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define MAX (20)

int N;
int min_value = 2000000;
int seq[MAX];
std::vector<int> sums;

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> seq[i];
}

void solve() {
  // Sort
  for (int i = 1; i < N; ++i) {
    for (int j = i; j > 0 && seq[j - 1] > seq[j]; --j) {
      std::swap(seq[j], seq[j - 1]);
    }
  }

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    if (sum + 1 < seq[i]) {
      break;
    }
    sum += seq[i];
  }
  
  std::cout << sum + 1;
}

int main() {
  input();
  solve();
}