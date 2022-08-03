// https://www.acmicpc.net/problem/1931
// 1931번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, cnt = 1;
vector<pii> meetings;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

void solve()
{
    int end = meetings[0].second;
    for (int i = 1; i < N; ++i)
    {
        if (meetings[i].first >= end)
        {
            cnt++;
            end = meetings[i].second;
        }
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int start, end;
        cin >> start >> end;
        pair<int, int> p;
        p.first = start;
        p.second = end;
        meetings.push_back(p);
    }

    sort(meetings.begin(), meetings.end(), cmp);

    solve();

    cout << cnt;

    return 0;
}