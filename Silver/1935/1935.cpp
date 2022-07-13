// https://www.acmicpc.net/problem/1935
// 1935번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve()
{
}

signed main()
{
    // fastio;
    solve();

    stack<double> stk;
    double arr[26] = {0};
    int operands_cnt;
    char ch;
    double a, b, result;
    string temp;

    cin >> operands_cnt;
    cin >> temp;
    for (int i = 0; i < operands_cnt; ++i)
    {
        cin >> arr[i];
    }
    int i = 0;
    while ((ch = temp[i++]) != '\0')
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            stk.push(arr[ch - 65]);
        }
        else
        {
            switch (ch)
            {
            case '+':
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                result = a + b;
                stk.push(result);
                break;
            case '-':
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                result = b - a;
                stk.push(result);
                break;
            case '*':
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                result = b * a;
                stk.push(result);
                break;
            case '/':
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                result = b / a;
                stk.push(result);
                break;
            default:
                break;
            }
        }
    }
    cout << fixed << setprecision(2) << stk.top();

    return 0;
}