// <https://www.acmicpc.net/problem/1021>
// 1021번 

#include <iostream>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

signed main() {
	fastio;
	
	int cnt = 0;
	int N = 0;
	int M = 0;
	deque<int> dq;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		dq.push_back(i + 1);
	for (int i = 0; i < M; ++i)
	{
		int input = 0;
		cin >> input;
		int key_idx;
		int dq_len = dq.size();
		for (int j = 0; j < dq_len; ++j)
		{
			if (dq[j] == input)
			{
				key_idx = j;
				break ;
			}
		}

		if ((double)key_idx >= dq_len / 2.0)
		{
			while (dq.front() != input)
			{
				int tmp = dq.back();
				dq.push_front(tmp);
				dq.pop_back();
				cnt++;
			}
		}
		else
		{
			while (dq.front() != input)
			{
				int tmp = dq.front();
				dq.push_back(tmp);
				dq.pop_front();
				cnt++;
			}
		}
		dq.pop_front();
	}
	cout << cnt << "\n";

	return (0);
}

/*
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 // pop_front


*/