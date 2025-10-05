#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void normalize(vector<pii> &piece) {
	sort(piece.begin(), piece.end());
	auto o = piece[0];
	for (auto &p : piece) {
		p.first -= o.first;
		p.second -= o.second;
	}
}

vector<pii> get_piece(vector<vector<int>> &m, int row, int col) {
	vector<pii> piece;
	queue<pii> q;

	m[row][col] = 1;
	q.push({row, col});

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		piece.push_back({curr.second, m.size() - curr.first - 1});
		int r = curr.first;
		int c = curr.second;

		for (int i = 0; i < 4; ++i) {
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (!(nc >= 0 && nc < m.size())) continue;
			if (!(nr>= 0 && nr < m.size())) continue;
			if (m[nr][nc] != 0) continue;
			m[nr][nc] = 1;
			q.push({nr, nc});
		}
	}
	normalize(piece);

	return piece;
}

void rotate(vector<pii> &piece) {
	for (auto &p : piece) {
		p = {p.second, -p.first};
	}
	normalize(piece);
}

vector<vector<pii>> find_pieces(vector<vector<int>> &m) {
	vector<vector<pii>> pieces;
	for (int row = 0; row < m.size(); ++row) {
		for (int col = 0; col < m.size(); ++col) {
			if (m[row][col] == 0) {
				pieces.push_back(get_piece(m, row, col));
			}
		}
	}
	return pieces;
}

bool match(vector<pii> &a, vector<pii> &b) {
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	for (auto &row : table) {
		for (auto &elem : row) {
			elem ^= 1;
		}
	}
	auto spaces = find_pieces(game_board);
	auto puzzles = find_pieces(table);

	auto all_puzzles = vector<vector<vector<pii>>>();
	for (auto &p : puzzles) {
		all_puzzles.push_back(vector<vector<pii>>());
		for (int i = 0; i < 4; ++i) {
			all_puzzles.back().push_back(p);
			if (i < 3) rotate(p);
		}
	}

	int answer = 0;
	for (auto  p : all_puzzles) {
		for (auto it = spaces.begin(); it != spaces.end(); ++it) {
			for (int i = 0; i < 4; ++i) {
				if (match(p[i], *it)) {
					answer += p[i].size();
					spaces.erase(it);
					goto OUT;
				}

			}
		}
		OUT: ;
	}

	return answer;
}
