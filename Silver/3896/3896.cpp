// <https://www.acmicpc.net/problem/3896>
// 3896번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX (1299709)

using namespace std;

static bool is_prime(int num)
{
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return (false);
	}
	return (true);
}

signed main() {
	fastio;
	int test_cnt = 0;
	
	cin >> test_cnt;
	for (int i = 0; i < test_cnt; ++i)
	{
		int input;
		int smaller = 0;
		int larger = 0;

		cin >> input;
		if (input <= 1 || is_prime(input))
		{
			cout << 0 << '\n';
			continue;
		}
		for (int j = input - 1; j >= 2; --j)
		{
			if (is_prime(j))
			{
				smaller = j;
				break;
			}
		}
		for (int j = input + 1; j <= MAX; ++j)
		{
			if (is_prime(j))
			{
				larger = j;
				break;
			}
		}
		if (smaller == 0 || larger == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		cout << larger - smaller << '\n';
	}
}
