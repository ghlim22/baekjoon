// https://www.acmicpc.net/problem/1966_2
// 1966_2번 

#include <iostream>
#include <deque>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	int test_cnt = 0;
	int paper_cnt;
	int key_idx;
	int init_idx;
	int priority;

	cin >> test_cnt;
	for (int i = 0; i < test_cnt; ++i)
	{
		cin >> paper_cnt >> key_idx;
		int cnt = 0;
		deque<pii> dq;
		for (int j = 0; j < paper_cnt; ++j)
		{
			pii tmp;
			cin >> tmp.first;
			tmp.second = j;
			dq.push_back(tmp);
		}
		while (!dq.empty())
		{
			int cur_priority = dq.front().first;
			bool is_prior = false;
			for (int j = 1; j < dq.size(); ++j)
			{
				if (dq[j].first > cur_priority)
					is_prior = true;
			}
			if (is_prior)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				cnt++;
				if (dq.front().second == key_idx)
				{
					cout << cnt << "\n";
					break ;
				}
				dq.pop_front();
			}
		}

	}
}

signed main() {
	fastio;
	solve();
}