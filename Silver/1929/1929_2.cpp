// https://www.acmicpc.net/problem/1929_2
// 1929_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

static bool is_prime(int num) {
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
	int lower, upper;

	cin >> lower >> upper;
	for (int i = lower; i <= upper; ++i)
	{
		if (is_prime(i))
			cout << i << '\n';
	}	
	return (0);
}