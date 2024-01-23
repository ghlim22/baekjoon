#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX_SIZE (100000)

int num[2][MAX_SIZE];
int dp[2][MAX_SIZE];
int t;
int n;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cin >> num[i][j];
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 2; ++j) {
				int sum = 0;
				dp[j][i] = num[j][i];
				if (i < n - 1) {
					sum = dp[j ^ 1][i + 1];
				}
				if (i < n - 2) {
					sum = std::max(sum, dp[0][i + 2]);
					sum = std::max(sum, dp[1][i + 2]);
				}
				dp[j][i] += sum;
			}
		}

		std::cout << std::max(dp[0][0], dp[1][0]) << '\n';
	}
}
