// https://www.acmicpc.net/problem/1107
// 1107번 

#include <iostream>
#include <limits.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int get_digit_cnt(int num)
{
	int cnt = 0;
	do
	{
		num /= 10;
		cnt++;
	} while (num > 0);
	return (cnt);
}

static bool check(int num, bool broken[])
{
	do
	{
		if (broken[num % 10])
			return (false);
		num /= 10;
	} while (num > 0);
	return (true);
}

void solve(const char *str, bool broken[]) 
{
	int dst = atoi(str);
	int cnt_pm = 0;
	int cnt = 0;
	int smaller;
	int larger;
	int cur;
	int cnt_s;
	int cnt_l;

	// 100에서 +/- 만으로 채널을 이동할 때.
	if (dst <= 100)
		cnt_pm = 100 - dst;
	else
		cnt_pm = dst - 100;

	// 원하는 채널에 가장 가까운 작은 수 구하기.
	// 구하지 못 하면 -1.
	for (cur = dst; cur >= 0; --cur)
	{
		if (cur == -1 || check(cur, broken))
			break ;
	}
	smaller = cur;

	// 원하는 채널에 가장 가까운 큰 수 구하기.
	// 구하지 못 하면 500001.
	for (cur = dst; cur < 1000000; ++cur)
	{
		if (check(cur, broken))
			break ;
	}
	larger = cur;

	if (smaller == -1)
	{
		cnt_s = INT_MAX;
	}
	else
	{
		cnt_s = dst - smaller;
		cnt_s += get_digit_cnt(smaller);
	}

	if (larger == INT_MAX)
	{
		cnt_l = INT_MAX;
	}
	else
	{
		cnt_l = larger - dst;
		cnt_l += get_digit_cnt(larger);
	}
	cnt = min(cnt_s, cnt_l);
	cnt = min(cnt, cnt_pm);
	cout << cnt;
}	

signed main() {
	fastio;
	char str[7];
	bool broken[10] = {false, };
	int broken_cnt = 0;

	cin >> str;
	cin >> broken_cnt;
	for (int i = 0; i < broken_cnt; ++i)
	{
		int input;
		cin >> input;
		broken[input] = true;
	}
	solve(str, broken);

	return (0);
}
