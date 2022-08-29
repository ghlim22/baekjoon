// https://www.acmicpc.net/problem/3003
// 3003번

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
    fastio;
    int king, queen, rook, bishop, knight, pawn;
    cin >> king >> queen >> rook >> bishop >> knight >> pawn;
    cout << 1 - king << " " << 1 - queen << " " << 2 - rook << " ";
    cout << 2 - bishop << " " << 2 - knight << " " << 8 - pawn;
    return 0;
}