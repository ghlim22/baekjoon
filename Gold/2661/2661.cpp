// https://www.acmicpc.net/problem/2661
// 2661번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

static int N;
static int arr[80];

static bool is_identical(int current_level)
{
	bool is_same_pattern;
	int partial_seq_len;

	for (partial_seq_len = 1; partial_seq_len <= (current_level + 1) / 2; ++partial_seq_len)
	{
		is_same_pattern = true;
		for (int i = 0; i < partial_seq_len; ++i)
		{
			if (arr[current_level - i] != arr[current_level - partial_seq_len - i])
			{
				is_same_pattern = false;
				break;
			}
		}
		if (is_same_pattern)
		{
			break ;
		}
	}
	return (is_same_pattern);
}

void solve(int level) 
{
	if (level == N)
	{
		for (int i = 0; i < N; ++i)
			cout << arr[i];
		exit(0);
	}
	for (int i = 1; i <= 3; ++i)
	{
		if (level > 0)
		{
			arr[level] = i;
			if (is_identical(level))
				continue;
			else
				solve(level + 1);
		}
		else
		{
			arr[level] = i;
			solve(level + 1);
		}
	}
}

signed main() 
{
	fastio;
	cin >> N;
	solve(0);
	return (0);
}