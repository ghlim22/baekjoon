// https://www.acmicpc.net/problem/18115_2
// 18115_2번 

#include <iostream>
#include <stack>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() 
{
	int n;
	int tmp;

	stack<int> st;
	deque<int> dq;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		st.push(input);
	}
	for (int i = 0; i < n; ++i)
	{
		int skill = st.top();
		st.pop();
		switch (skill)
		{
		case 1:
			dq.push_front(i + 1);
			break;
		case 2:
			tmp = dq.front();
			dq.pop_front();
			dq.push_front(i + 1);
			dq.push_front(tmp);
			break ;
		case 3:
			dq.push_back(i + 1);
			break ;
		default:
			break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << dq[i];
		if (i < n - 1)
			cout << " ";
	}
}

signed main() {
	fastio;
	solve();
}