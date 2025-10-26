#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

int set[4000001];

int find(int x) {
	if (x == set[x]) {
		return x;
	}
	return set[x] = find(set[x]);
}

void merge(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);

	if (rootx < rooty) {
		std::swap(rootx, rooty);
	}

	set[rooty] = rootx; // 더 큰 수가 집합의 대푯값이 됨.
}

int main(void) {
  fastio;
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<int> deck;
  for (int i = 0; i < m; ++i) {
	int card;
	std::cin >> card;
	deck.push_back(card);
  }

  std::sort(deck.begin(), deck.end());
  deck.insert(deck.begin(), 0);

  for (int i = 1; i < deck.size(); ++i) {
	std::fill(set + deck[i - 1] + 1, set + deck[i] + 1, deck[i]);
  }

  for (int i = 0; i < k; ++i) {
	int card;
	std::cin >> card;
	int choice = find(card + 1);
	std::cout << choice << '\n';
	merge(choice, choice + 1);
  }

  return 0;
}