// https://www.acmicpc.net/problem/1931_3
// 1931_3번 

#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int, int>

using namespace std;

static vector< pii > schedule;

static bool compare(pii a, pii b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second < b.second);
}

void solve(int cnt) {
	int end = schedule[0].second;
	int ans = 1;

	for (int i = 1; i < cnt; ++i)
	{
		if (end <= schedule[i].first)
		{
			end = schedule[i].second;
			ans++;
		}
	}

	cout << ans;
}

signed main() {
	fastio;

	int cnt = 0;

	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int start, end;

		cin >> start >> end;
		schedule.push_back(make_pair(start, end));
	}
	sort(schedule.begin(), schedule.end(), compare);
	solve(cnt);

	return (0);
}