// https://www.acmicpc.net/problem/22983
// 22983번 

#include <iostream>
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static int N;
static int M;
static int chess[3000][3000];
static int ans = 0;

void solve(int row, int col) 
{
	for (int i )
}

signed main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char c;
			scanf(" %c", &c);
			if (c == 'B')
				chess[i][j] = 1;
			else
				chess[i][j] = 0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{

		}
	}

	



	solve();
}