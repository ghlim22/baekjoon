// https://www.acmicpc.net/problem/20301_2
// 20301_2번 

#include <iostream>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	int n = 0;
	int k = 0;
	int m = 0;
	int cnt = 0;
	int output;
	bool is_reverse = false;
	deque<int> dq;

	cin >> n >> k >> m;
	for (int i = 0; i < n; ++i)
		dq.push_back(i + 1);
	while (!dq.empty())
	{
		for (int i = 0; i < k - 1; ++i)
		{
			if (is_reverse)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			else
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		if (is_reverse)
		{
			output = dq.back();
			dq.pop_back();
		}
		else
		{
			output = dq.front();
			dq.pop_front();
		}
		cout << output << "\n";
		cnt++;
		if (cnt == m)
		{
			is_reverse ^= 1;
			cnt = 0;
		}
	}
}

signed main() {
	fastio;
	solve();
}