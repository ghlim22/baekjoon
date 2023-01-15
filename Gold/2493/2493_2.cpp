// https://www.acmicpc.net/problem/2493_2
// 2493_2번 

#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static int	arr[500000] = {0, };

signed main() 
{
	fastio;
	int n;
	pii tmp;
	stack<pii> st;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp.first;
		tmp.second = i + 1;
		while (!st.empty() && st.top().first < tmp.first) // 스택이 비어있지 않다면 더 높은 탑이 나올 때까지 pop().
			st.pop();
		if (!st.empty())
			arr[i] = st.top().second;
		st.push(tmp); // 높이보다 위치가 우선되기 때문에 일단 다 push().
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
		if (i < n - 1)
			cout << " ";
	}
	return (0);
}
