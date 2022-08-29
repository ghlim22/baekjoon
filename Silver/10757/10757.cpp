// https://www.acmicpc.net/problem/10757
// 10757번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve(string &s1, string &s2)
{
    string output = "";
    int round = 0;
    int sum = 0;

    while (round > 0 || !s1.empty() || !s2.empty())
    {
        int a, b;

        if (!s1.empty())
        {
            a = s1.back();
            a -= '0';
            sum += a;
            s1.pop_back();
        }

        if (!s2.empty())
        {
            b = s2.back();
            b -= '0';
            sum += b;
            s2.pop_back();
        }

        if (round > 0)
        {
            sum += round;
        }

        round = sum / 10;
        sum %= 10;
        output.push_back(sum + '0');
        sum = 0;
    }

    reverse(output.begin(), output.end());
    cout << output;
}

signed main()
{
    fastio;
    string input1, input2;
    cin >> input1 >> input2;
    solve(input1, input2);
    return 0;
}