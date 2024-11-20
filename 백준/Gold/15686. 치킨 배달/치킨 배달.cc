#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

struct pos {
  int y;
  int x;
};

int N;
int M;
int ANSWER = INT_MAX;
std::vector<pos> houses;
std::vector<pos> chickens;
std::vector<std::vector<int>> dist(13);

void comb(int start, int k, int choose) {
  if (k == M) {
    std::vector<int> min_dist(houses.size(), INT_MAX);
    for (int i = 0; i < chickens.size(); ++i) {
      if (choose & (1 << i)) {
        for (int j = 0; j < dist[i].size(); ++j) {
          min_dist[j] = std::min(min_dist[j], dist[i][j]);
        }
      }
    }

    int sum = 0;
    for (int d : min_dist) {
      sum += d;
    }
    ANSWER = std::min(sum, ANSWER);

    return;
  }

  for (int i = start; i < chickens.size(); ++i) {
    comb(i + 1, k + 1, choose | (1 << i));
  }
}

int main(void) {
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int num;
      std::cin >> num;
      if (num == 1) {
        houses.push_back(pos{.y = i, .x = j});
      } else if (num == 2) {
        chickens.push_back(pos{.y = i, .x = j});
      }
    }
  }

  for (int i = 0; i < chickens.size(); ++i) {
    for (pos h : houses) {
      dist[i].push_back(std::abs(chickens[i].y - h.y) +
                        std::abs(chickens[i].x - h.x));
    }
  }

  comb(0, 0, 0);

  std::cout << ANSWER;

  return 0;
}