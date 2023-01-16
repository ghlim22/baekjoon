// https://www.acmicpc.net/problem/1158
// 1158번 

#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void solve(int n, int k) 
{
	queue<int> q;
	
	for (int i = 1; i <= n; ++i)
		q.push(i);
	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
}

signed main() {
	fastio;
	int N, K;
	cin >> N >> K;
	solve(N, K);
	return (0);
}