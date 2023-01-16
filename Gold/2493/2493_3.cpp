// <https://www.acmicpc.net/problem/2439_3>
// 2439_3번 

#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() 
{
	int n;
	stack<pii> stk;
	pii tmp;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		tmp.first = i + 1;
		cin >> tmp.second;
		while (!stk.empty())
		{
			if (stk.top().second > tmp.second)
			{
				cout << stk.top().first << " ";
				break ;
			}
			stk.pop();
		}
		if (stk.empty())
			cout << "0 ";
		stk.push(tmp);
	}
	return ;
}

signed main() {
	fastio;
	solve();
}