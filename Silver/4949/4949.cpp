// <https://www.acmicpc.net/problem/4949>
// 4949번 

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

signed main()
{
	char	s[110];
	stack<char> stk;

	while (true)
	{
		fgets(s, 110, stdin);
		if (s[0] == '.')
			break ;
		int len = strlen(s);
		bool is_symmetry = true;
		for (int i = 0; i < len && is_symmetry; ++i)
		{
			switch (s[i])
			{
			case '(':
				stk.push('(');
				break ;
			case '[':
				stk.push('[');
				break ;
			case ')':
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
					is_symmetry = false;
				break ;
			case ']':
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
					is_symmetry = false;
				break ;
			default:
				break;
			}
		}
		if (!stk.empty())
			is_symmetry = false;
		while (!stk.empty())
			stk.pop();
		if (is_symmetry)
			cout << "yes\n";
		else
			cout << "no\n";
	}		
	return (0);
}