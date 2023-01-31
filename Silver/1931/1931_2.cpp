// https://www.acmicpc.net/problem/1931_2
// 1931_2번 

#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX (100000)

using namespace std;

static bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second < b.second);
}

signed main() {
	fastio;

	int cnt = 0;
	vector< pair<int, int> > calendar;

	cin >> cnt;
	for (int i = 0; i < cnt; ++i){
		int start, end;

		cin >> start >> end;
		calendar.push_back(make_pair(start, end));
	}

	sort(calendar.begin(), calendar.end(), compare);

	bool is_selected = false;
	int i = 0;
	int ans = 1;
	do
	{
		is_selected = false;
		for (int j = i + 1; j < cnt; ++j)
		{
			if (calendar[i].second <= calendar[j].first)
			{
				is_selected = true;
				ans++;
				i = j;
				break ;
			}
		}
	} while (is_selected && i < cnt);
	
	cout << ans;

	return (0);
}