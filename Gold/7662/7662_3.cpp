// <https://www.acmicpc.net/problem/7662_3>
// 7662_3번 

#include <iostream>
#include <set>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;
signed main()
{
	fastio;

	int		test_cnt;
	int		op_cnt;
	int 	num;
	char	op;

	cin >> test_cnt;
	while (test_cnt--)
	{
		cin >> op_cnt;
		multiset<int> ms;
		while (op_cnt--)
		{
			cin >> op;
			if (op == 'I')
			{
				cin >> num;
				ms.insert(num);
			}
			else if (op == 'D')
			{
				cin >> num;
				if (ms.empty())
					continue;
				if (num == 1)
					ms.erase(prev(ms.end()));
				else if (num == -1)
					ms.erase(ms.begin());
			}
		}
		if (ms.empty())
			cout << "EMPTY\n";
		else
			cout << *ms.begin() << ' ' << *prev(ms.end());
	}

	return (0);
}