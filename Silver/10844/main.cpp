#include <iostream>
#define M (1000000000)
static int arr[101][10];
int main(void)
{
	int n;
	unsigned long ans = 0;

	std::cin >> n;
	/* DP initialization */
	for (int i = 1; i <= 9; ++i)
		arr[1][i] = 1;
	/* DP[i][j]: i for length, j for last digit */
	/* DP[i][j] = DP[i - 1][1], where j is 0.
				  DP[i - 1][8], where j is 9.
				  DP[i - 1][j - 1] + DP[i - 1][j + 1], for else.
	*/
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
				arr[i][j] = arr[i - 1][1] % M;
			else if (j == 9)
				arr[i][j] = arr[i - 1][8] % M;
			else
				arr[i][j] = (arr[i - 1][j - 1] % M + arr[i - 1][j + 1] % M) % M;
		}
	}
	for (int i = 0; i <= 9; ++i)
		ans += (arr[n][i] % M);
	std::cout << ans % M;
	return (0);
}
