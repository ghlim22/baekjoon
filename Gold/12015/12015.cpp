// https://www.acmicpc.net/problem/12015
// 12015번 

#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_SIZE (1000000)

using namespace std;

static int inputs[MAX_SIZE];
static int lis[MAX_SIZE];
static int n = 0;
static int lis_cnt = 0;

signed main() {
	fastio;

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> inputs[i];

	lis[0] = inputs[0];
	lis_cnt++;
	for (int i = 1; i < n; ++i)
	{
		int lis_idx = lower_bound(lis, lis + lis_cnt, inputs[i]) - lis;
		if (lis_idx == lis_cnt)
			lis_cnt++;
		lis[lis_idx] = inputs[i];
	}
	cout << lis_cnt;

	return (0);
}