#include <algorithm>
#include <cmath>
#include <cstdio>
#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

int D[201][201];
int M[201][201];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= n; ++j) {
		if (i != j) D[i][j] = 200*100+100;
	}
  }

  for (int i = 0; i < m; ++i) {
	int s, e, l;
	scanf("%d %d %d", &s, &e, &l);
	D[s][e] = std::min(D[s][e], l);
	D[e][s] = D[s][e];

	M[s][e] = std::max(M[s][e], l);
	M[e][s] = M[s][e];
  }

  for (int k = 1; k <= n; ++k) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
		}
	}
  }

  double answer = 200 * 100 + 100;
  for (int start = 1; start <= n; ++start) {
	double maxtime = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			double time = std::max(D[start][i], D[start][j]);
			int diff = std::abs(D[start][i] - D[start][j]);
			time += (M[i][j] - diff) / 2.0;
			maxtime = std::max(time, maxtime);
		}
	}
	answer = std::min(maxtime, answer);
  }

  printf("%02.1f\n", answer);

  return 0;
}