// https://www.acmicpc.net/problem/1149_2
// 1149_2번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

typedef enum
{
	RED, GREEN, BLUE
} e_color;

static int paint_cost[1000][3];

signed main() {
	fastio;

	int house_cnt = 0;
	int ans = 0;

	cin >> house_cnt;
	cin >> paint_cost[0][RED] >> paint_cost[0][GREEN] >> paint_cost[0][BLUE];
	for (int i = 1; i < house_cnt; ++i)
	{
		int red, green, blue;

		cin >> red >> green >> blue;
		paint_cost[i][RED] = red + min(paint_cost[i - 1][BLUE], paint_cost[i - 1][GREEN]);
		paint_cost[i][BLUE] = blue + min(paint_cost[i - 1][RED], paint_cost[i - 1][GREEN]);
		paint_cost[i][GREEN] = green + min(paint_cost[i - 1][RED], paint_cost[i - 1][BLUE]);
	}
	ans = min(paint_cost[house_cnt - 1][RED], paint_cost[house_cnt - 1][GREEN]);
	ans = min(ans, paint_cost[house_cnt - 1][BLUE]);
	cout << ans;

	return (0);
}