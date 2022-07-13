// https://www.acmicpc.net/problem/10773
// 10773번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve(int n)
{
}

signed main()
{
    fastio;
    int n;
    stack<int> stk;
    cin >> n;
    while (n--)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            stk.pop();
        }
        else
        {
            stk.push(temp);
        }
    }
    int sum = 0;
    while (!stk.empty())
    {
        int temp = stk.top();
        stk.pop();
        sum += temp;
    }
    cout << sum;

    return 0;
}