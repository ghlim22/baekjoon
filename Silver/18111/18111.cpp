// https://www.acmicpc.net/problem/18111
// 18111번 

#include <iostream>
#include <limits.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define UPPERBOUND (256)
#define LOWERBOUND (0)

using namespace std;

static const int INF = 0x3f3f3f3f;
static int row;
static int col;
static int inventory;
static int arr[257];
static int ans_time = INT_MAX;
static int ans_height;

void solve() {
	for (int height = 256; height >= 0; --height)
	{
		int cur_inven = inventory;
		int cur_time = 0;
		// 목표 높이보다 높은 블록의 개수 세기.
		for (int i = height + 1; i <= UPPERBOUND; ++i)
		{
			cur_inven += (i - height) * arr[i];
			cur_time += 2 * (i - height ) * arr[i];
		}
		// 목표 높이보다 낮은 블록의 개수 세기.
		for (int i = 0; i < height; ++i)
		{
			cur_inven -= (height - i) * arr[i];
			cur_time += (height - i ) * arr[i];
			if (cur_inven < 0)
				break ;
		}
		if (cur_inven < 0 || cur_time >= ans_time)
			continue ;
		ans_time = cur_time;
		ans_height = height;
	}
}

signed main() {
	fastio;
	cin >> row >> col >> inventory;
	for (int i = 0; i < row * col; ++i)
	{
		int input;
		cin >> input;
		arr[input]++;
	}
	solve();
	cout << ans_time << ' ' << ans_height;
	return (0);
}