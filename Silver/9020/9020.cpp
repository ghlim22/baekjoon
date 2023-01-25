// <https://www.acmicpc.net/problem/9020>
// 9020번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static bool prime_nums[10001] = {false, };
static bool visited[10001] = {false, };

static void fill_arr(void)
{
	for (int i = 2; i <= 10000; ++i)
	{
		if (!prime_nums[i] && !visited[i])
		{
			prime_nums[i] = true;
			visited[i] = true;
			for (int j = i * i; j <= 10000; j += i)
			{
				visited[j] = true;
			}			
		}
	}
}

signed main() {
	fastio;
	int test_cnt = 0;

	cin >> test_cnt;
	fill_arr();
	for (int i = 0; i < test_cnt; ++i)
	{
		int input = 0;
		int smaller = 0;
		int larger = 0;

		cin >> input;
		for (int i = input / 2; i >= 2; --i)
		{
			if (prime_nums[i])
			{
				bool found = false;
				smaller = i;
				for (int j = input / 2; j <= 10000; ++j)
				{
					if (prime_nums[j] && smaller + j == input)
					{
						larger = j;
						found = true;
						break;
					}
				}
				if (found)
				{
					cout << smaller << ' ' << larger << '\n';
					break;
				}
			}
		}
	} 

	return (0);
}