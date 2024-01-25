#include <iostream>

#define MAX_SIZE (10000)

int tree[MAX_SIZE];
int size;

void input()
{
	int i = 0;
	int num = 0;
	while (std::cin >> num) {
		tree[i++] = num;
	}
	size = i;
}

/* [start, end) */
void solve(int start, int end)
{
	int i;

	if (start >= end) {
		return;
	}
	for (i = start + 1; i < end && tree[i] < tree[start]; ++i) {
		;
	}
	solve(start + 1, i); /* left */
	solve(i, end); /* right */
	std::cout << tree[start] << '\n'; /* root */
}

int main(void)
{
	input();
	solve(0, size);
	return 0;
}
