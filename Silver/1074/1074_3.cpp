// https://www.acmicpc.net/problem/1074_3
// 1074_3번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

typedef enum e_quadrant
{
	FIRST, SECOND, THIRD, FOURTH
} t_quadrant;

int get_power(int base, int exp)
{
	int res = 1;

	while (exp)
	{
		if (exp & 1)
		{
			res = res * base;
		}
		base = base * base;
		exp >>= 1;
	}
	return (res);
}

static int solve(int n, int start_r, int start_c, int r, int c, int cnt) 
{
	int size = get_power(2, n);
	int quadrant_cnt = size / 2 * size / 2;
	t_quadrant place;

	if (n == 0)
		return (cnt);

	if (r < start_r + size / 2 && c < start_c + size / 2)
		place = FIRST;
	else if (r < start_r + size / 2 && c >= start_c + size / 2)
		place = SECOND;
	else if (r >= start_r + size / 2 && c < start_c + size / 2)
		place = THIRD;
	else
		place = FOURTH;
	
	switch (place)
	{
	case FIRST:
		return (solve(n - 1, start_r, start_c, r, c, cnt));
	case SECOND:
		cnt += quadrant_cnt;
		return (solve(n - 1, start_r, start_c + size / 2, r, c, cnt));
	case THIRD:
		cnt += quadrant_cnt * 2;
		return (solve(n - 1, start_r + size / 2, start_c, r, c, cnt));
	case FOURTH:
		cnt += quadrant_cnt * 3;
		return (solve(n - 1, start_r + size / 2, start_c + size / 2, r, c, cnt));
	default:
		break;
	}
}

signed main() {
	fastio;

	int n, r, c;

	cin >> n >> r >> c;
	cout << solve(n, 0, 0, r, c, 0);
	return (0);
}