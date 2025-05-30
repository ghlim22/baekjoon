#include <cstring>
#include <iostream>

int N;
int nums[101];
long long D[101][21];

int main()
{
	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		std::cin >> nums[i];
	}

	D[1][nums[1]] = 1;
	for (int i = 2; i <= N - 1; ++i) {
		int cur = nums[i];
		for (int j = 0; j <= 20; ++j) {
			if (D[i - 1][j] == 0) {
				continue;
			}
			int sum = j + nums[i];
			if (sum >= 0 && sum <= 20) {
				D[i][sum] += D[i - 1][j];
			}
			sum = j - nums[i];
			if (sum >= 0 && sum <= 20) {
				D[i][sum] += D[i - 1][j];
			}
		}
	}
	std::cout << D[N - 1][nums[N]];
	
	return 0;
}