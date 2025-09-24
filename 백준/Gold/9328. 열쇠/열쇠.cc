#include <cctype>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

struct point {
	int row;
	int col;
};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
char map[100][100];
bool key[26];
bool V[100][100];
int h;
int w;

void input() {
	std::cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < w; ++j) {
			map[i][j] = s[j];
		}
	}
	std::string s;
	std::cin >> s;
	if (s[0] == '0') {
		return;
	}
	for (char c : s) {
		key[c - 'a'] = true;
	} 
}

void find_entrance(std::queue<point> &Q, std::list<point> &L) {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (!(i == 0 || i == h - 1) && (j > 0 && j < w - 1)) {
				continue;
			}
			if (std::isupper(map[i][j])) {
				V[i][j] = true;
				L.push_back({i, j});
			} else if (map[i][j] != '*') {
				V[i][j] = true;
				Q.push({i, j});
			}
		}	
	}
}


int solve() {
	int ret = 0;
	std::queue<point> Q;
	std::list<point> L;

	find_entrance(Q, L);

	while (true) {
		for (auto it = L.begin(); it != L.end();) {
			int idx = map[it->row][it->col] - 'A';
			if (key[idx]) {
				V[it->row][it->col] = true;
				Q.push({it->row, it->col});
				it = L.erase(it);
			} else {
				++it;
			}
		}

		if (Q.empty()) {
			break;
		}

		while (!Q.empty()) {
			const point &curr = Q.front();
			int r = curr.row;
			int c = curr.col;

			if (std::islower(map[r][c])) {
				key[map[r][c] - 'a'] = true;	
			}
			if (map[r][c] == '$') {
				ret += 1;
			}

			for (int i = 0; i < 4; ++i) {
				int nr = r + dy[i];
				int nc = c + dx[i];
				if (!(nr >= 0 && nr < h && nc >= 0 && nc < w))
					continue;
				if (map[nr][nc] == '*')
					continue;
				if (V[nr][nc])
					continue;
				V[nr][nc] = true;
				if (std::isupper(map[nr][nc]))
					L.push_back({nr, nc});
				else
					Q.push({nr, nc});	
			}	
			Q.pop();
		}
	}

	return ret;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::memset(key, 0, sizeof(key));
		std::memset(V, 0, sizeof(V));
		input();
		std::cout << solve() << '\n';
	}
	return 0;
}