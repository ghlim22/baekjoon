#include <algorithm>
#include <iostream>
#include <climits>
#define MAX_SIZE 1000

static int arr[MAX_SIZE + 1];

int main(void)
{
	int t;
	int n;
	int maximum = 0;

	std::cin >> t;
	while (t--)
	{
		maximum = INT_MIN;
		std::cin >> n;
		for (int i = 1; i <= n; ++i)
			std::cin >> arr[i];
		for (int i = 1; i <= n; ++i)
		{
			int partial_sum = 0;
			for (int j = i; j <= n; ++j)
			{
				partial_sum += arr[j];
				maximum = std::max(maximum, partial_sum);
			}	
		}
		std::cout << maximum << std::endl;	
	}
	return 0;
}
