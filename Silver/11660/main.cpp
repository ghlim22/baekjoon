#include <cstring>
#include <iostream>
#define MAX_SIZE 1024
int main(void)
{
	int n;
	int m;
	int input;
	int	pSum[MAX_SIZE + 1][MAX_SIZE + 1];

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::memset(pSum, 0, sizeof(pSum));
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> input;
			if (j == 1)
				pSum[i][j] = input;
			else
			 	pSum[i][j] = input + pSum[i][j - 1];
		}
	}

	while (m--) 
	{	
		int x1, y1, x2, y2, sum = 0;

		std::cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i <= x2; ++i)
		{
			sum += pSum[i][y2] - pSum[i][y1 - 1];
		}

		std::cout << sum << '\n';	
	}


/* Naive approach - timeout

	while (m--) 
	{
		int x1, y1, x2, y2, sum = 0;

		std::cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1 - 1; i < x2; ++i)
		{
			for (int j = y1 - 1; j < y2; ++j)
				sum += arr[i][j];
		}
		std::cout << sum << '\n';
	}
*/
	return 0;
}
