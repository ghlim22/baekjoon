// https://www.acmicpc.net/problem/1927
// 1927번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void solve()
{
}

signed main()
{
    fastio;
    int N;
    priority_queue<int, vector<int>, cmp> pque;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;

        if (temp == 0)
        {
            if (pque.empty())
            {
                cout << 0;
            }
            else
            {
                cout << pque.top();
                pque.pop();
            }
            cout << '\n';
        }
        else
        {
            pque.push(temp);
        }
    }

    return 0;
}