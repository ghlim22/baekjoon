#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> pii;

struct dust {
	int r;
	int c;
	int value;
};

int R, C, T;
int MAP[1000][1000];
int DX[4] = {0, 0, -1, 1};
int DY[4] = {-1, 1, 0, 0};

int spread(int r, int c, int dust) {
	int count = 0;
	for (int i = 0; i < 4; ++i) {
		int nr = r + DY[i];
		int nc = c + DX[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C)
			continue;
		if (MAP[nr][nc] == -1)
			continue;
		MAP[nr][nc] += dust / 5;
		count++;
	}
	return count;
}

void spread_all() {
	std::vector<dust> dusts;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (MAP[i][j] > 0) {
				dusts.push_back({i, j, MAP[i][j]});
			}
		}
	}

	for (dust d : dusts) {
		int count = spread(d.r, d.c, d.value);
		MAP[d.r][d.c] -= d.value / 5 * count;
	}
}

void wind(int upper, int lower) {
	// upper
	// column 0
	for (int i = upper - 1; i > 0; --i) {
		MAP[i][0] = MAP[i - 1][0];
	}
	for (int i = 0; i < C - 1; ++i) {
		MAP[0][i] = MAP[0][i + 1];
	}
	for (int i = 0; i < upper; ++i) {
		MAP[i][C - 1] = MAP[i + 1][C - 1];
	}
	for (int i = C - 1; i > 1; --i) {
		MAP[upper][i] = MAP[upper][i - 1];
	}
	MAP[upper][1] = 0;

	// lower
	for (int i = lower + 1; i < R - 1; ++i) {
		MAP[i][0] = MAP[i + 1][0];
	}
	for (int i = 0; i < C - 1; ++i) {
		MAP[R - 1][i] = MAP[R - 1][i + 1];
	}
	for (int i = R - 1; i > lower; --i) {
		MAP[i][C - 1] = MAP[i - 1][C - 1];
	}
	for (int i = C - 1; i > 1; --i) {
		MAP[lower][i] = MAP[lower][i - 1];
	}
	MAP[lower][1] = 0;
}

int main() {
	std::cin >> R >> C >> T;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j)
			std::cin >> MAP[i][j];
	}

	int upper;
	int lower;
	for (int i = 0; i < R; ++i) {
		if (MAP[i][0] == -1) {
			upper = i;
			break;
		}
	}
	lower = upper + 1;


	while (T--) {
		spread_all();
		wind(upper, lower);
	}

	int sum = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (MAP[i][j] > 0) {
				sum += MAP[i][j];
			}
		}
	}

	std::cout << sum;

	return 0;
}