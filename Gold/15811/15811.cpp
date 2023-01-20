// https://www.acmicpc.net/problem/15811
// 15811번 

#include <iostream>
#include <string.h>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static char strs[3][20];
static int 	conversion_arr[26];
static bool is_used_num[10] = {false, };
static bool done_flag = false;
static int used_cnt = 0;
static vector<char> vc;

static ll get_num(const char *str)
{
	int len = strlen(str);
	ll res = 0;
	for (int i = 0; i < len; ++i)
	{
		res = 10 * res + conversion_arr[str[i] - 'A'];
	}
	return (res);
}

void solve(int level) 
{
	if (done_flag)
		return ;

	if (level == used_cnt)
	{
		if (get_num(strs[2]) == get_num(strs[0]) + get_num(strs[1]))
		{
			done_flag = true;
		}
		return ;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (!is_used_num[i])
		{
			is_used_num[i] = true;
			conversion_arr[vc[level] - 'A'] = i;
			solve(level + 1);
			is_used_num[i] = false;
		}
	}
}

signed main() 
{
	fastio;
	bool is_used_char[26] = {false, };
	for (int i = 0; i < 3; ++i)
		cin >> strs[i];
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; strs[i][j]; ++j)
		{
			if (!is_used_char[strs[i][j] - 'A'])
			{
				is_used_char[strs[i][j] - 'A'] = true;
				vc.push_back(strs[i][j]);
				used_cnt++;
			}
		}
	}

	solve(0);

	if (done_flag)
		cout << "YES";
	else
		cout << "NO";
	
	return (0);
}