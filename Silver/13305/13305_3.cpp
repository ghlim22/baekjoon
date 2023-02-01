// https://www.acmicpc.net/problem/13305_3
// 13305_3번 

#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static vector<ll> gas;
static vector<ll> distance_map;

signed main() {
	fastio;

	int n = 0;
	ll spending = 0;

	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int input;
		cin >> input;
		distance_map.push_back(input);
	}
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		gas.push_back(input);
	}

	for (int cur = 0; cur < n - 1; ++cur)
	{
		ll cur_price = gas[cur];
		int next = cur + 1;
		spending += distance_map[cur] * cur_price;
		for (; next < n; ++next)
		{
			if (gas[next] <= cur_price)
				break ;
			spending += distance_map[next] * cur_price;
		}
		cur = next - 1;
	}
	cout << spending;

	return (0);
}