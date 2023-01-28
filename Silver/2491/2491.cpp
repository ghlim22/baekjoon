// https://www.acmicpc.net/problem/2491
// 2491번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

signed main() {
	fastio;
	int cnt = 0;
	int prev_num = 0;
	int cur_num = 0;
	int prev_ascending_len = 0;
	int cur_ascending_len = 0;
	int prev_descending_len = 0;
	int cur_descending_len = 0;
	int max_len = 1;

	cin >> cnt;
	cin >> prev_num;
	prev_descending_len = 1;
	prev_ascending_len = 1;
	for (int i = 1; i < cnt; ++i)
	{
		cur_ascending_len = 0;
		cur_descending_len = 0;
		cin >> cur_num;
		if (prev_num <= cur_num)
			cur_ascending_len = prev_ascending_len;
		if (prev_num >= cur_num)
			cur_descending_len = prev_descending_len;
		cur_ascending_len++;
		cur_descending_len++;
		prev_num = cur_num;
		prev_ascending_len = cur_ascending_len;
		prev_descending_len = cur_descending_len;
		max_len = max(max_len, cur_ascending_len);
		max_len = max(max_len, cur_descending_len);
	}
	cout << max_len;
}