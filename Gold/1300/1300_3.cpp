// https://www.acmicpc.net/problem/1300_3
// 1300_3번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	
}

signed main() {
	fastio;
	
	int array_size = 0;
	int key_idx = 0;
	int start = 0;
	int end = 0;
	int mid = 0;
	ll	below_cnt = 0;

	cin >> array_size >> key_idx;

	start = 0;
	end = key_idx;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		below_cnt = 0;
		for (int i = 1; i <= array_size; ++i)
		{
			below_cnt += min(array_size, mid / i);
			if (i > mid)
				break ;
		}
		if (below_cnt >= key_idx)
			end = mid;
		else
			start = mid + 1;
	}
	cout << start;

	return (0);
}