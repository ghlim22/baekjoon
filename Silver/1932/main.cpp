#include <algorithm>
#include <cstring>
#include <iostream>

int main(void)
{
	int ans = 0;
	int input;
	int n;
	int arr[501][501];

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::memset(arr, 0, sizeof(arr));

	std::cin >> n;
	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= i; ++j)
		{
			std::cin >> input;
			arr[i][j] = input + std::max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; ++i)
		ans = std::max(ans, arr[n][i]);

	std::cout << ans << '\n';
	
	return 0;
}
