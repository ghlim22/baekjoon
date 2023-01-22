// https://www.acmicpc.net/problem/15811_2
// 15811_2번 

#include <iostream>
#include <vector>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static char strs[3][20];
static vector<char> vc;
static int alphabet_cnt = 0;
static bool success_flag = false;
static bool is_used_num[10] = {false, };
static int conversion_table[26] = {0, };

static ll convert_num(const char *str)
{
	int len = strlen(str);
	ll	num = 0;

	for (int i = 0; i < len; ++i)
	{
		num = num * 10 + conversion_table[str[i] - 'A'];
	}

	return (num);
}

void solve(int lv)
{
	if (success_flag)
	{
		return ;
	}
	if (alphabet_cnt == lv)
	{
		if (convert_num(strs[2]) == convert_num(strs[0]) + convert_num(strs[1]))
			success_flag = true;
		return ;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (!is_used_num[i])
		{
			is_used_num[i] = true;
			conversion_table[vc[lv] - 'A'] = i;
			solve(lv + 1);
			is_used_num[i] = false;
		}
	}
}

signed main() 
{
	fastio;
	bool is_appeared[26] = {false, };
	for (int i = 0; i < 3; ++i)
	{
		cin >> strs[i];
		int len = strlen(strs[i]);
		for (int j = 0; j < len; ++j)
		{
			if (!is_appeared[strs[i][j] - 'A'])
			{
				is_appeared[strs[i][j] - 'A'] = true;
				vc.push_back(strs[i][j]);
				alphabet_cnt++;
			}
		}
	}
	if (alphabet_cnt >= 10)
	{
		cout << "NO";
		return (0);
	}
	solve(0);
	if (success_flag)
		cout << "YES";
	else
		cout << "NO";
	return (0);
}