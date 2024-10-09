#include <iostream>
#include <queue>
#include <utility>

#define MAX (1000)

typedef std::pair<int, int> pii_t;

bool visited[MAX * 2 + 1][MAX * 2 + 1];

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int S;

  std::cin >> S;

  std::queue<pii_t> q;

  int cost = 0;
  q.push(std::make_pair(1, 0));
  while (!q.empty()) {
	int size = q.size();
	while (size--) {
		int screen = q.front().first;
		int clipboard = q.front().second;
		q.pop();
		if (screen == S) {
			std::cout << cost;
			return 0;
		}

		int ns[3] = {screen, screen + clipboard, screen - 1};
		int nc[3] = {screen, clipboard, clipboard};
		for (int i = 0; i < 3; ++i) {
			if (i == 1 && clipboard == 0)
				continue;
			if (!(ns[i] >= 0 && ns[i] <= 2 * S))
				continue;
			if (!(nc[i] >= 0 && nc[i] <= 2 * S))
				continue;
			if (visited[ns[i]][nc[i]])
				continue;
			visited[ns[i]][nc[i]] = true;
			q.push(std::make_pair(ns[i], nc[i]));
		}
	}
	cost++;
  }

  return 0;
}
