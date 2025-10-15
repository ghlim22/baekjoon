#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#define MAX 1000000

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

int main(void) {
  fastio;

  int N;
  std::cin >> N;

  std::vector<int> scores(N);
  std::vector<int> index_of(MAX + 1);
  std::vector<int> cards(N);
  std::fill(index_of.begin(), index_of.end(), -1);
  for (int i = 0; i < N; ++i) {
	int num;
	std::cin >> num;
	index_of[num] = i;
	cards[i] = num;
  }

  for (int i = 0; i < N; ++i) {
	int multiple = cards[i] * 2;
	while (multiple <= MAX) {
		if (index_of[multiple] != -1) {
			scores[index_of[multiple]]--;
			scores[index_of[cards[i]]]++;
		}
		multiple += cards[i];
	}
  }

  for (int score : scores)
  	std::cout << score << ' ';

  return 0;
}