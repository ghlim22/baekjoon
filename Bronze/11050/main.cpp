#include <iostream>
static int func(int n, int k);
int main(void)
{
	int N;
	int K;

	std::cin >> N >> K;
	std::cout << func(N, K);
	return 0;
}

static int func(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	if (k == 1)
		return n;
	return func(n - 1, k - 1) + func(n - 1, k);
}