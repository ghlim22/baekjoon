// https://www.acmicpc.net/problem/1914
// 1914번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
//#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve()
{
}

// big integer
// source: https://daydreamx.tistory.com/entry/baekjoon1914
// 다시 구현해보기!
void power(int n, int x, char arr[])
{
    int temp = 0, last = 0, cnt = 0;
    arr[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= last; ++j)
        {
            temp = arr[j] * x + cnt;
            if (temp >= 10)
            {
                arr[j] = temp % 10;
                cnt = temp / 10;
                if (j == last)
                {
                    arr[++last] = cnt;
                    cnt = 0;
                    break;
                }
            }
            else
            {
                arr[j] = temp;
                cnt = 0;
            }
        }
    }
    arr[0] -= 1;
    for (int i = last; i >= 0; i--)
    {
        printf("%d", arr[i]);
        // cout << arr[i];
    }
    // printf("\n");
}

void move_print(int start, int dest)
{
    cout << "\n"
         << start << " " << dest;
}

void hanoi_tower_print(int n, int start, int temp, int dest)
{
    if (n == 1)
    {
        move_print(start, dest);
        return;
    }

    hanoi_tower_print(n - 1, start, dest, temp);
    move_print(start, dest);
    hanoi_tower_print(n - 1, temp, start, dest);
}

signed main()
{
    fastio;
    int n;
    cin >> n;
    char result[35] = {0};
    power(n, 2, result);
    if (n <= 20)
    {
        hanoi_tower_print(n, 1, 2, 3);
    }

    return 0;
}