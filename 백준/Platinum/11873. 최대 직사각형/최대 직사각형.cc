#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

int mat[1000][1000];
int hist[1000];

struct bar
{
	int index;
	int height;
};

int solve(int n, int m)
{
	std::memset(hist, 0, sizeof(hist));
	int maxArea = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 0) {
				hist[j] = 0;
			} else {
				hist[j] += 1;
			}
		}

		std::stack<bar> s;
		for (int j = 0; j < m; ++j) {
			bar cur = {j, hist[j]};
			while (!s.empty() && s.top().height >= cur.height) {
				maxArea = std::max(maxArea, (j - s.top().index) * s.top().height);
				cur.index = s.top().index;
				s.pop();
			}
			if (cur.height != 0) {
				s.push(cur);
			}
		}
		while (!s.empty()) {
			maxArea = std::max(maxArea, (m - s.top().index) * s.top().height);
			s.pop();
		}
	}

	return maxArea;
}

int main()
{
	for (;;) {
		int n;
		int m;
		std::cin >> n >> m;
		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				std::cin >> mat[i][j];
		}

		std::cout << solve(n, m) << std::endl;
	}

	return 0;
}