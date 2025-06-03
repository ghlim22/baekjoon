#include <algorithm>
#include <cstring>
#include <iostream>

int A[1000];
int D[1000][1001];
int N, M;

int f(int index, int count)
{
	if (index == N) {
		return 0;
	}
	if (D[index][count] != -1) {
		return D[index][count];
	}
	int space = M - count + 1;
	space *= space;
	int cost = space + f(index + 1, A[index] + 1);
	if (count + A[index] <= M) {
		cost = std::min(cost, f(index + 1, count + A[index] + 1));
	}
	D[index][count] = cost;
	return cost;
}

int main()
{
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
		std::cin >> A[i];

	std::memset(D, -1, sizeof(D));

	std::cout << f(0, 0);
	return 0;
}