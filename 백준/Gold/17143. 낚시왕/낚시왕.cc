#include <cstring>
#include <iostream>
#include <vector>

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
	bool alive;
};

shark *board[101][101];
shark *after[101][101];
int R, C, M;
std::vector<shark> sharks;

int fish(int col) {
	for (int row = 1; row <= R; ++row) {
		if (board[row][col] != NULL && board[row][col]->alive) {
			shark *sh = board[row][col];
			sh->alive = false;
			board[row][col] = NULL;
			return sh->z;
		}
	}
	return 0;
}

void move(shark &sh) {
	int r = sh.r;
	int c = sh.c;
	int distance = sh.s;
	while (distance > 0) {
		switch (sh.d) {
			case UP:
			if (sh.r - distance <= 1) {
				distance -= (sh.r - 1);
				sh.r = 1;
				sh.d = DOWN;
			} else {
				sh.r -= distance;
				distance = 0;
			}
			break;

			case DOWN:
			if (sh.r + distance >= R) {
				distance -= (R - sh.r);
				sh.r = R;
				sh.d = UP;
			} else {
				sh.r += distance;
				distance = 0;
			}
			break;

			case RIGHT:
			if (sh.c + distance >= C) {
				distance -= (C - sh.c);
				sh.c = C;
				sh.d = LEFT;
			} else {
				sh.c += distance;
				distance = 0;
			}
			break;

			case LEFT:
			if (sh.c - distance <= 1) {
				distance -= (sh.c - 1);
				sh.c = 1;
				sh.d = RIGHT;
			} else {
				sh.c -= distance;
				distance = 0;
			}
			break;
		}
	}

	if (after[sh.r][sh.c] != NULL) {
		if (after[sh.r][sh.c]->z > sh.z) {
			sh.alive = false;
			return;
		} 
		after[sh.r][sh.c]->alive = false;
		after[sh.r][sh.c] = NULL;
	}
	after[sh.r][sh.c] = &sh;	
}

void move_sharks() {
	for (shark &sh : sharks) {
		if (!sh.alive) {
			continue;
		}
		move(sh);
	}
	std::memcpy(board, after, sizeof(board));
	std::memset(after, 0, sizeof(after));
}

int main() {
	std::cin >> R >> C >> M;
	sharks.resize(M);
	for (int i = 0; i < M; ++i) {
		sharks[i].alive = true;
		std::cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
		board[sharks[i].r][sharks[i].c] = &sharks[i];
	}

	int sum = 0;
	for (int col = 1; col <= C; ++col) {
		sum += fish(col);
		move_sharks();
	}
	std::cout << sum << std::endl;

	return 0;
}