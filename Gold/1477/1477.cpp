// https://www.acmicpc.net/problem/1477
// 1477번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;



void solve() {
	
}

signed main() {
	fastio;

	int current_rest_cnt = 0;
	int new_rest_cnt = 0;
	int len = 0;
	int start = 0;
	int end = 0;
	int mid = 0;
	int cnt = 0;
	
	cin >> current_rest_cnt >> new_rest_cnt >> len;

	int rest_services[current_rest_cnt + 2];
	int interval[current_rest_cnt + 1];

	rest_services[0] = 0;
	rest_services[current_rest_cnt + 1] = len;
	for (int i = 1; i <= current_rest_cnt; ++i)
		cin >> rest_services[i];
	sort(rest_services, rest_services + current_rest_cnt + 2);
	for (int i = 1; i < current_rest_cnt + 2; ++i)
		interval[i - 1] = rest_services[i] - rest_services[i - 1];
	/*
	cout << '\n';
	for (int i = 0; i < current_rest_cnt + 1; ++i)
		cout << interval[i] << ' ';
	cout << '\n';
	*/

	start = 1;
	end = len;
	while (start <= end)
	{
		cnt = 0;
		mid = start + (end - start) / 2;
		for (int i = 0; i < current_rest_cnt + 1; ++i)
			cnt += (interval[i] - 1) / mid;
		/*
		cout << '\n' << "start: " << start << " end: " << end << " mid: " << mid << " cnt: " << cnt << '\n';
		*/
		if (cnt > new_rest_cnt)
			start = mid + 1;
		else
			end = mid - 1;
		
	}
	cout << start;

	return (0);
}