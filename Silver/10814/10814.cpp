// https://www.acmicpc.net/problem/10814
// 10814번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define pis pair<int, string>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N;
vector<pis> v;
pis arr[100000];

bool cmp_pair(pis a, pis b)
{
    return a.first < b.first;
}

void solve()
{
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        pair<int, string> temp;
        cin >> temp.first >> temp.second;
        arr[i] = temp;
    }

    stable_sort(arr, arr + N, cmp_pair);

    for (int i = 0; i < N; ++i)
    {
        cout << arr[i].first << " " << arr[i].second << (i == N - 1 ? "" : "\n");
    }

    return 0;
}