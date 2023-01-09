// <https://www.acmicpc.net/problem/2164>
// 2164번 

#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

void solve() {
	int N;
	int ans;
	int top;
	queue<int> cards;

	cin >> N;
	for (int i = 0; i < N; ++i)
		cards.push(i + 1);
	while (cards.size() > 1)
	{
		cards.pop();
		if (cards.size() == 1)
			break;
		top = cards.front();
		cards.pop();
		cards.push(top);
	}
	ans = cards.front();
	cout << ans;
}

signed main() {
	fastio;
	solve();
}