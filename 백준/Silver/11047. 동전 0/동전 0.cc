#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int coins[10];

signed main() {
	fastio;

	int ans = 0;
	int sum = 0;
	int cnt = 0;

	cin >> cnt >> sum;
	for (int i = 0; i < cnt; ++i)
		cin >> coins[i];
	for (int i = cnt - 1; i >= 0 && sum > 0; --i)
	{
		if (sum >= coins[i])
		{
			ans += sum / coins[i];
			sum %= coins[i];
		}
	}
	cout << ans;

	return (0);
}