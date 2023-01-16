// <https://www.acmicpc.net/problem/24511>
// 24511번 

#include <iostream>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static bool is_que[100000];

signed main() 
{
	fastio;

	int N = 0;
	int M = 0;
	int que_cnt = 0;
	int que_idx = 0;
	deque<int> dq;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			is_que[i] = true;
			que_cnt++;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		if (is_que[i])
		{
			dq.push_back(input);
		}
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int input;
		cin >> input;
		dq.push_front(input);
		int output = dq.back();
		dq.pop_back();
		cout << output;
		if (i < M - 1)
			cout << " ";
	}

	return (0);
}