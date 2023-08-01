#include <iostream>
#include <algorithm>
#include <limits.h>

typedef long long ll;

static ll arr[5000];

static ll get_abs(ll n)
{
	return n < 0 ? -n : n;
}

int main(void)
{
	int N;
	int first;
	int second;
	int third;
	ll	ans = LLONG_MAX;

	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
	std::sort(arr, arr + N);
	for (int i = 0; i < N; ++i)
	{
		int left = 0;
		int right = N - 1;
		while (left < i && i < right)
		{
			ll tmp = arr[left] + arr[i] + arr[right];
			if (get_abs(tmp) < ans)
			{
				first = left;
				second = i;
				third = right;
				ans = get_abs(tmp);
			}

			if (tmp == 0)
			{
				std::cout << arr[first] << ' ' << arr[second] << ' ' << arr[third] << std::endl;
				return 0;
			}
			else if (tmp < 0)
				left++;
			else
				right--;
		}
	}
	std::cout << arr[first] << ' ' << arr[second] << ' ' << arr[third] << std::endl;
	return 0;
}