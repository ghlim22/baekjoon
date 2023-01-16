// https://www.acmicpc.net/problem/5430
// 5430번 

#include <iostream>
#include <deque>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
	int test_cnt = 0;
	
	cin >> test_cnt;
	for (int i = 0; i < test_cnt; ++i)
	{
		deque<int> dq;
		char *funcs = (char *)malloc(100010);
		char *arr = (char *)malloc(400010);
		char *endptr = NULL;
		int	element_cnt = 0;
		char c;

		cin >> funcs;
		cin >> element_cnt;
		cin >> arr;
		char *tmp = arr;
		for (int j = 0; j < element_cnt;)
		{
			c = *tmp;
			if (isdigit(c))
			{
				dq.push_back((int)strtol(tmp, &endptr, 10));
				tmp = endptr;
				j++;
			}
			else
			{
				tmp++;
			}
		}
		int len = strlen(funcs);
		bool is_reverse = false;
		bool is_error = false;
		for (int j = 0; !is_error && j < len; ++j)
		{
			switch (funcs[j])
			{
			case 'R':
				is_reverse ^= 1;
				break;
			case 'D':
				if (dq.empty())
				{
					is_error = true;
				}
				else if (is_reverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
				break ;
			default:
				break;
			}
		}
		if (is_error)
		{
			cout << "error";
		}
		else if (is_reverse)
		{
			cout << "[";
			for (int j = dq.size() - 1; j >= 0; --j)
			{
				cout << dq[j];
				if (j > 0)
					cout << ",";
			}
			cout << "]";
		}
		else
		{
			cout << "[";
			int size = dq.size();
			for (int j = 0; j < size; ++j)
			{
				cout << dq[j];
				if (j < size - 1)
					cout << ",";
			}
			cout << "]";
		}
		cout << "\n";	
		free(arr);
		free(funcs);
	}
}

signed main() {
	fastio;
	solve();
}