#include <iostream>
#include <string>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

string str, exp;
deque<char> dq;

bool is_exp(void)
{
	for (int i = 0; i < exp.length(); ++i)
	{
		if (dq[dq.size() - 1 - i] != exp[exp.size() - 1 - i])
			return (false);
	}
	return (true);
}

void solve(void) 
{
	int str_len = str.length();
	for (int i = 0; i < str_len; ++i)
	{
		dq.push_back(str[i]);
		if (dq.size() < exp.length())
			continue;
		if (is_exp())
		{
			for (int i = 0; i < exp.length(); ++i)
				dq.pop_back();
		}
	}
	if (dq.size() == 0)
	{
		cout << "FRULA";
		return ;
	}
	for (int i = 0; i < dq.size(); ++i)
		cout << dq[i];
}

signed main() {
	fastio;
	cin >> str >> exp;
	solve();
	return (0);
}
