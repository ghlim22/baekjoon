#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

typedef std::vector<char> chv;
typedef std::vector<std::string> sv;

std::string vector_to_string(const sv &v) {
  return v[0] + '-' + v[1] + '-' + v[2];
}

bool check(const sv &v) {
  for (int i = 0; i < 3; ++i) {
    for (char c : v[i]) {
      if (c != ('A' + i))
        return false;
    }
  }
  return true;
}

int solve(const sv &input) {
  std::set<std::string> s;
  std::queue<sv> q;

  s.insert(vector_to_string(input));
  q.push(input);

  for (int cost = 0; q.empty() == false; ++cost) {
    int len = q.size();
    while (len--) {
      const sv &current = q.front();
      if (check(current)) {
        return cost;
      }

      for (int i = 0; i < 3; ++i) {
        if (current[i].size() == 0)
          continue;
        for (int j = 0; j < 3; ++j) {
          if (i == j)
            continue;
          sv n = current;
          n[j] += n[i].back();
          n[i].pop_back();
          std::string key = vector_to_string(n);
          if (s.find(key) != s.end())
            continue;
          s.insert(key);
          q.push(n);
        }
      }

      q.pop();
    }
  }

  return -1;
}

int main(void) {
  fastio;
  sv input(3, "");
  for (int i = 0; i < 3; ++i) {
    int size;
    std::cin >> size;
    if (size > 0)
      std::cin >> input[i];
  }
  std::cout << solve(input) << std::endl;

  return 0;
}