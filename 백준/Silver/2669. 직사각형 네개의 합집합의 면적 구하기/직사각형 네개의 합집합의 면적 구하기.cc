#include <iostream>

int board[101][101];

int main() {
	int x1, y1, x2, y2;
	for (int i = 0; i < 4; ++i) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; ++x) {
			for (int y = y1; y < y2; ++y) {
				board[x][y] = 1;
			}
		}
	}

	int area = 0;
	for (int x = 1; x <= 100; ++x) {
		for (int y = 1; y <= 100; ++y) {
			if (board[x][y]) area++;
		}
	}
	std::cout << area;
	
	return 0;
}