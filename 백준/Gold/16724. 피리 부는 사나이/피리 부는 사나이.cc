#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

char map[1000][1000];
int visited[1000][1000];

int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};

int N, M;

int dfs(int y, int x) {
	if (visited[y][x] == 1) {
		return 1;
	}
	if (visited[y][x] == 2) {
		return 0;
	}

	visited[y][x] = 1;

	int d = map[y][x];
	int ny = y + dy[d];
	int nx = x + dx[d];

	int ret = dfs(ny, nx);
	visited[y][x] = 2;

	return ret;
}

int main(void) {
  fastio;
  std::cin >> N >> M;

  for (int i = 0; i < N; ++i) {
	std::string s;
	std::cin >> s;
	for (int j = 0; j < M; ++j) {
		if (s[j] == 'U') map[i][j] = 0;
		else if (s[j] == 'D') map[i][j] = 1;
		else if (s[j] == 'L') map[i][j] = 2;
		else if (s[j] == 'R') map[i][j] = 3;
	}
  }

  int components = 0;
  for (int i = 0; i < N; ++i) {
	for (int j = 0; j < M; ++j) {
		if (visited[i][j] == 0) {
			components += dfs(i, j);
		}
	}
  }

  std::cout << components << std::endl;

  return 0;
}