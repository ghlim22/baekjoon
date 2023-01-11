// <https://www.acmicpc.net/problem/24511>
// 24511번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

static int queuestack[100000];
static int values[100000];

signed main() {
	fastio;

	int N;
	int M;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> queuestack[i];
	}
	for (int i = 0; i < N; ++i)
		cin >> values[i];
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int element;
		cin >> element;
		for (int j = 0; j < N; ++j)
		{
			if (queuestack[j]) // stack
			{
				continue;
			}
			else // queue
			{
				int tmp = values[j];
				values[j] = element;
				element = tmp;
			}
		}
		cout << element << " ";
	}

	return (0);
}