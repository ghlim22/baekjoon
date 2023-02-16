// <https://www.acmicpc.net/problem/15811_3>
// 15811_3번 

#include <iostream>
#include <vector>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long

using namespace std;

static vector<char> alphabets;
static int alphabet_cnt = 0;
static bool successed = false;
static int convert_table[26];
static bool is_used[10];
static char strs[3][20];

static ll convert_num(char *str, int len)
{
	ll res = 0;
	for (int i = 0; i < len; ++i)
	{
		int c = str[i];
		res = res * 10 + convert_table[c - 'A'];	
	}
	return (res);	
}

static void solve(int lv) 
{
	if (successed)
		return ;
	if (lv == alphabet_cnt)
	{
		if (convert_num(strs[0], strlen(strs[0])) + convert_num(strs[1], strlen(strs[1])) == convert_num(strs[2], strlen(strs[2])))
			successed = true;
		return ;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (!is_used[i])
		{
			int c = alphabets[lv];
			is_used[i] = true;
			convert_table[c - 'A'] = i;
			solve(lv + 1);
			is_used[i] = false;
		}
	}
}

signed main() {
	fastio;

	bool is_appeared[26] = {false, };

	for (int i = 0; i < 3; ++i)
	{
		cin >> strs[i];
		int len = strlen(strs[i]);
		for (int j = 0; j < len; ++j)
		{
			char c = strs[i][j];
			if (!is_appeared[c - 'A'])
			{
				is_appeared[c - 'A'] = true;
				alphabets.push_back(c);
				alphabet_cnt++;
			}
		}
	}

	if (alphabet_cnt > 10)
	{
		cout << "NO";
		return (0);
	}

	solve(0);
	
	if (successed)
		cout << "YES";
	else
		cout << "NO";

	return (0);
}