// <https://www.acmicpc.net/problem/9012_2>
// 9012_2번 

#include <iostream>
#include <stack>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)

using namespace std;

signed main() {
	fastio;
	
	int test_cnt = 0;
	stack<char> st;

	cin >> test_cnt;
	for (int i = 0; i < test_cnt; ++i)
	{
		int len = 0;
		char line[51] = {0, };
		cin >> line;
		len = strlen(line);
		for (int j = 0; j < len; ++j)
		{
			if (line[j] == '(')
				st.push('(');
			else if (line[j] == ')')
			{
				if (st.empty())
				{
					goto NO;
				}
				st.pop();
			}
		}
		if (st.empty())
		{
			cout << "YES\n";
		}
		else
		{
			NO:
			cout << "NO\n";
			while (!st.empty())
				st.pop();
		}
	}	
	return 0;
}