#include <cstdio>
#include <string>
#include <vector>

int K;
char input[9];
int num[10];
int visited[10];
int is_first = 1;
std::vector<std::vector<int> > vec;

void print() {
  for (int i = 0; i < K + 1; ++i) {
    printf("%d", vec.front()[i]);
  }
  printf("\n");
  for (int i = 0; i < K + 1; ++i) {
    printf("%d", vec.back()[i]);
  }
}

void solve(int len) {
  if (len == K + 1) {
    std::vector<int> v;
    for (int i = 0; i < len; ++i)
      v.push_back(num[i]);
    vec.push_back(v);
    return;
  }
  for (int i = 9; i >= 0; --i) {
    if (visited[i]) {
      continue;
    }
    if (len > 0 && input[len - 1] == '>' && num[len - 1] < i) {
      continue;
    }
    if (len > 0 && input[len - 1] == '<' && num[len - 1] > i) {
      continue;
    }
    visited[i] = 1;
    num[len] = i;
    solve(len + 1);
    visited[i] = 0;
  }
}

int main(void) {
  scanf("%d", &K);
  for (int i = 0; i < K; ++i) {
    scanf(" %c", &input[i]);
  }
  solve(0);
  print();
  return 0;
}