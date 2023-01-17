// <https://www.acmicpc.net/problem/2231_2>
// 2231_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;


int get_digit_cnt(int num)
{
	int sum = 0;
	do
	{
		sum += num % 10;
		num /= 10;
	} while (num);
	return (sum);
}

void solve() {
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int digit_sum = get_digit_cnt(i);
		if (i + digit_sum == n)
		{
			cout << i;
			return ;
		}
	}
	cout << '0';
	return ;
}

signed main() {
	fastio;
	solve();
	return (0);
}