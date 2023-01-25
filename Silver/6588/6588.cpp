// <https://www.acmicpc.net/problem/6588>
// 6588번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static bool is_prime(int num)
{
	if (num <= 1)
		return (false);
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return (false);
	}
	return (true);
}

signed main() {
	fastio;
	while (true)
	{
		int input = 0;
		int smaller = 0;
		int larger = 0;
		bool found = false;

		cin >> input;
		if (input == 0)
		{
			break;
		}
		for (int i = 3; i <= input / 2; i += 2)
		{
			if (is_prime(i) && is_prime(input - i))
			{
				found = true;
				smaller = i;
				larger = input - i;
				break ;
			}
		}
		if (found)
			cout << input << " = " << smaller << " + " << larger << '\n';
	}

	return (0);
}
