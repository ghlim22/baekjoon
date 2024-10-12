#include <iostream>
#include <vector>

int N;
int max_sum;
std::vector<char> characters;
std::vector<std::string> words;
bool appeared[26];
bool used[10];
int conversion[26];

void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::string word;

    std::cin >> word;
    words.push_back(word);

    for (int i = 0; i < word.size(); ++i) {
      int idx = word[i] - 'A';
      if (appeared[idx] == false) {
        appeared[idx] = true;
        characters.push_back(word[i]);
      }
    }
  }
}

int word_to_int(const std::string &w) {
  int res = 0;
  for (int i = 0; i < w.size(); ++i) {
    res *= 10;
    res += conversion[w[i] - 'A'];
  }
  return res;
}

void bruteforce(int level) {
  if (level == characters.size()) {
    int sum = 0;
    for (std::string &w : words) {
      sum += word_to_int(w);
    }
    max_sum = (sum > max_sum) ? sum : max_sum;
    return;
  }

  for (int digit = 0; digit <= 9; ++digit) {
    if (used[digit] == true)
      continue;

    conversion[characters[level] - 'A'] = digit;

    used[digit] = true;
    bruteforce(level + 1);
    used[digit] = false;
  }
}

void solve() {
  bruteforce(0);
  std::cout << max_sum;
}

int main() {
  input();
  solve();
  return 0;
}