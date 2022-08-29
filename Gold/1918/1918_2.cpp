// https://www.acmicpc.net/problem/1918_2
// 1918_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

stack<char> res;
stack<char> op;

bool is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return true;
    }
    return false;
}

bool is_prior(char ch)
{
    if (op.empty())
    {
        return true;
    }

    if (op.top() == '(')
    {
        return true;
    }

    if (op.top() == '+' || op.top() == '-')
    {
        if (ch == '*' || ch == '/')
        {
            return true;
        }
    }

    return false;
}

void print()
{
    if (res.empty())
    {
        return;
    }
    char ch = res.top();
    res.pop();
    print();
    cout << ch;
    return;
}

signed main()
{
    fastio;
    char ch;

    while (cin >> ch)
    {
        // operand
        if (isalpha(ch))
        {
            res.push(ch);
        }

        // operator
        if (is_operator(ch))
        {
            if (is_prior(ch))
            {
                op.push(ch);
            }
            else
            {
                while (!is_prior(ch))
                {
                    res.push(op.top());
                    op.pop();
                }
                op.push(ch);
            }
        }

        // parentheses
        if (ch == '(')
        {
            op.push(ch);
        }

        if (ch == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                res.push(op.top());
                op.pop();
            }
            op.pop(); // pop '(' from the operator's stack.
        }
    }

    // push remain operators to result stack.
    while (!op.empty())
    {
        res.push(op.top());
        op.pop();
    }

    print();

    return 0;
}