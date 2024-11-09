#include <iostream>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int digit = 10;
  int character = 26;
  int answer = 1;

  std::string line;
  std::cin >> line;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == 'c') {
      answer *= character;
      character = 25;
      digit = 10;
    } else {
      answer *= digit;
      digit = 9;
      character = 26;
    }
  }

  std::cout << answer;

  return 0;
}