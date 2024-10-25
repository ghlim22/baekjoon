#include <iostream>
#include <string>

int N;
int K;
int MAX_WORD_CNT = 0;
int WORDS[50];
int CHARS[21];

void solve(int count, int mask, int cur) {
  if (count == K - 5 || cur >= 21) {
    int word_cnt = 0;
    for (int i = 0; i < N; ++i) {
      int word = WORDS[i];
      if ((mask & word) == word)
        word_cnt++;
    }
    MAX_WORD_CNT = (word_cnt > MAX_WORD_CNT) ? word_cnt : MAX_WORD_CNT;
    return;
  }

  solve(count + 1, mask | (1 << CHARS[cur]), cur + 1);
  solve(count, mask, cur + 1);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> K;

  if (K < 5) {
    std::cout << 0;
    return 0;
  }

  for (int i = 0; i < N; ++i) {
    std::string word;
    std::cin >> word;
    for (char c : word) {
      switch (c) {
      case 'a':
      case 'n':
      case 't':
      case 'i':
      case 'c':
        break;
      default:
        WORDS[i] |= (1 << (c - 'a'));
      }
    }
  }

  for (int i = 0, j = 0; i < 26; ++i) {
    char c = 'a' + i;
    switch (c) {
    case 'a':
    case 'n':
    case 't':
    case 'i':
    case 'c':
      break;
    default:
      CHARS[j++] = i;
    }
  }

  solve(0, 0, 0);
  std::cout << MAX_WORD_CNT;

  return 0;
}