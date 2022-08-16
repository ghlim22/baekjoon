// https://www.acmicpc.net/problem/10826
// 10826번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

string seq[10001];
int N;

string string_add(string a, string b)
{
    string result;
    int sum = 0;
    while (!a.empty() || !b.empty() || sum)
    {
        if (!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }

        result.push_back(sum % 10 + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

void solve(int n)
{
    seq[0] = "0";
    seq[1] = "1";
    for (int i = 2; i <= n; ++i)
    {
        seq[i] = string_add(seq[i - 1], seq[i - 2]);
    }
    cout << seq[n];
}

signed main()
{
    fastio;
    cin >> N;
    solve(N);
    return 0;
}