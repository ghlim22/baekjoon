// <https://www.acmicpc.net/problem/14502>
// 14502번 

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define pii pair<int, int>

using namespace std;
typedef tuple< pii, pii, pii > tp;
static int N, M;
static int board[8][8];
static int ans = 0;
static vector<tp> combs;

static void combination(vector< pii > &arr, vector< pii > &comb, int index, int r, int depth)
{
	if (r == 0)
	{
		combs.push_back(make_tuple(comb[0], comb[1], comb[2]));
		return ;
	}
	else if (depth == (int)arr.size())
	{
		return ;
	}
	else
	{
		// choose arr[depth].
		comb[index] = arr[depth];
		combination(arr, comb, index + 1, r - 1, depth + 1);
		// not choose arr[depth].
		combination(arr, comb, index, r, depth + 1);
	}
}

static void put_wall(tp &wall_info)
{
	pii first = get<0>(wall_info);
	pii second = get<1>(wall_info);
	pii third = get<2>(wall_info);

	board[first.first][first.second] = 1;
	board[second.first][second.second] = 1;
	board[third.first][third.second] = 1;
}

static void restore_wall(tp &wall_info)
{
	pii first = get<0>(wall_info);
	pii second = get<1>(wall_info);
	pii third = get<2>(wall_info);

	board[first.first][first.second] = 0;
	board[second.first][second.second] = 0;
	board[third.first][third.second] = 0;
}

static void bfs(bool infected[][8], int start_row, int start_col, int *safe_cnt)
{
	queue< pii > q;

	q.push(make_pair(start_row, start_col));
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;	
		q.pop();
		if (i > 0 && !infected[i - 1][j] && !board[i - 1][j])
		{
			--*safe_cnt;
			infected[i - 1][j] = true;
			q.push(make_pair(i - 1, j));
		}
		if (i < N - 1 && !infected[i + 1][j] && !board[i + 1][j])
		{
			--*safe_cnt;
			infected[i + 1][j] = true;
			q.push(make_pair(i + 1, j));
		}
		if (j > 0 && !infected[i][j - 1] && !board[i][j - 1])
		{
			--*safe_cnt;
			infected[i][j - 1] = true;
			q.push(make_pair(i, j - 1));
		}
		if (j < M - 1 && !infected[i][j + 1] && !board[i][j + 1])
		{
			--*safe_cnt;
			infected[i][j + 1] = true;
			q.push(make_pair(i, j + 1));
		}
	}
}

static int cnt_safearea(int zero_cnt)
{
	bool	infected[8][8];
	int		safe_cnt = zero_cnt - 3;

	memset(infected, 0, sizeof(infected));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!infected[i][j] && board[i][j] == 2)
				bfs(infected, i, j, &safe_cnt);
		}
	}
	return (safe_cnt);
}

static void solve(void)
{
	vector< pii > arr;
	vector< pii > combi(64);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (!board[i][j])
				arr.push_back(make_pair(i, j));
		}
	}
	combination(arr, combi, 0, 3, 0);

	for (int i = 0; i < (int)combs.size(); ++i)
	{
		tp temp = combs[i];
		put_wall(combs[i]);		
		ans = max(ans, cnt_safearea(arr.size()));
		restore_wall(temp);
	}
	cout << ans;
}

signed main()
{
	fastio;
	solve();
	return (0);
}