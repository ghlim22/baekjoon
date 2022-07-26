// https://www.acmicpc.net/problem/1065
// 1065번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
int N, ans = 0;

void solve(int num);
int get_digit_cnt(int n);
int get_num(int n, int i);

void solve(int num)
{
    for (int i = 1; i <= num; ++i)
    {
        int digit_cnt = get_digit_cnt(i);
        if (digit_cnt <= 2)
        {
            ans++;
        }
        else
        {
            bool is_han = true;
            int difference = get_num(i, 1) - get_num(i, 0);
            for (int j = 1; j < digit_cnt - 1; ++j)
            {
                if (difference != (get_num(i, j + 1) - get_num(i, j)))
                {
                    is_han = false;
                    break;
                }
            }

            if (is_han)
            {
                ans++;
            }
        }
    }
}

// n이 몇 자리인지 구한다.
int get_digit_cnt(int n)
{
    int cnt = 0;
    while (n)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

// 뒤에서 i번째 자릿수의 수를 가져온다.
int get_num(int n, int i)
{
    return n / (int)pow(10, i) % 10;
}

signed main()
{
    fastio;
    cin >> N;
    solve(N);

    cout << ans;

    return 0;
}