// https://www.acmicpc.net/problem/1918_3
// 1918_3번 

#include <iostream>
#include <stack>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)

using namespace std;

int get_priority(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return (1);
	case '*':
	case '/':
		return (2);
	default:
		return (0);
	}
}

int op_compare(char token, char in_stack)
{
	return (get_priority(token) > get_priority(in_stack));
}

char	*solve(char *expression) 
{
	int len = strlen(expression);
	char *postfix_expression = (char *)malloc(len + 1);
	int pos = 0;
	stack<char> op_stack;

	for (int i = 0; i < len; ++i)
	{
		char token = expression[i];
		if (isupper(token)) // operand.
		{
			postfix_expression[pos++] = token;
			continue;
		}
		if (op_stack.empty())
		{
			op_stack.push(token);
			continue;
		}
		if (token == '(')
		{
			op_stack.push('(');
			continue;
		}
		if (token == ')')
		{
			while (!op_stack.empty() && op_stack.top() != '(')
			{
				postfix_expression[pos++] = op_stack.top();
				op_stack.pop();
			}
			if (!op_stack.empty() && op_stack.top() == '(')
				op_stack.pop();
			continue;
		}
		if (op_compare(token, op_stack.top()))
		{
			op_stack.push(token);
		}
		else
		{
			while (!op_stack.empty() && op_stack.top() != '(' && !op_compare(token, op_stack.top()))
			{
				postfix_expression[pos++] = op_stack.top();
				op_stack.pop();
			}
			op_stack.push(token);
		}
	}
	while (!op_stack.empty())
	{
		postfix_expression[pos++] = op_stack.top();
		op_stack.pop();
	}

	postfix_expression[pos] = '\0';
	return (postfix_expression);
}

signed main() 
{
	fastio;

	char expression[101];
	cin >> expression;
	cout << solve(expression);
	return (0);
}