#include <iostream>
#include <queue>
#include <string>
#include <utility>

int main() {
  std::string s, t;

  std::cin >> s >> t;

  int answer = 0;
  std::queue<std::string> q;
  q.push(t);
  while (!q.empty()) {
    const std::string &f = q.front();
    if (f.compare(s) == 0) {
      answer = 1;
      break;
    }
    if (f.size() > s.size()) {
      if (f.back() == 'A') {
          q.push(f.substr(0, f.size() - 1));
      }
      if (f.front() == 'B') {
		  std::string r = f.substr(1);
		  int size = r.size();
		  int lmt = r.size() / 2;
		  for (int i = 0; i < lmt; ++i) {
			std::swap(r[i], r[size - 1 - i]);
		  }
		  q.push(r);
      }
    }
    q.pop();
  }

  std::cout << answer;

  return 0;
}