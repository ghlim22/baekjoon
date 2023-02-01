// <https://www.acmicpc.net/problem/27112>
// 27112번 

#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int, int>

using namespace std;

vector< pii > work_schedule;

static bool is_weekend(int day)
{
	return ((day + 1) % 7 == 0 || day % 7 == 0);
}

signed main() {
	fastio;

	int work_cnt = 0;
	int last_day = 0;
	int total_extra = 0;

	cin >> work_cnt;
	for (int i = 0; i < work_cnt; ++i)
	{
		int deadline, load;

		cin >> deadline >> load;
		work_schedule.push_back(make_pair(deadline, load));
		last_day = max(last_day, deadline);
	}

	sort(work_schedule.begin(), work_schedule.end());

	int weekday = 0;
	int extra = 0;
	int work_num = 0;
	for (int i = 1; i <= last_day; ++i)
	{
		if (is_weekend(i))
		{
			extra++;
		}
		else
		{
			weekday++;
			extra++;
		}

		while (work_num < work_cnt && work_schedule[work_num].first == i)
		{
			if (work_schedule[work_num].second <= weekday)
			{
				weekday -= work_schedule[work_num].second;
			}
			else
			{
				work_schedule[work_num].second -= weekday;
				weekday = 0;
				if (work_schedule[work_num].second <= extra)
				{
					total_extra += work_schedule[work_num].second;
					extra -= work_schedule[work_num].second;
				}
				else
				{
					cout << -1;
					exit(0);
				}
			}
			work_num++;
		}
	}

	cout << total_extra;

	return (0);
}