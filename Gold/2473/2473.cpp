// https://www.acmicpc.net/problem/2467
// 2473번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

ll N;
ll arr[100001];

ll absolute(ll n)
{
    if (n < 0)
    {
        return -n;
    }
    return n;
}

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve()
{
}

signed main()
{
    fastio;
    solve();

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int ans_one;
    int ans_two;
    int ans_three;
    ll sum_of_three = LONG_LONG_MAX;
    for (int i = 0; i < N; ++i)
    {
        int left = 0;
        int right = N - 1;

        while (left < i && i < right)
        {
            ll temp = arr[left] + arr[i] + arr[right];
            if (absolute(temp) < absolute(sum_of_three))
            {
                ans_one = left;
                ans_two = i;
                ans_three = right;
                sum_of_three = temp;
            }

            if (temp > 0)
            {
                right--;
            }
            else if (temp < 0)
            {
                left++;
            }
            else
            {
                cout << arr[ans_one] << " " << arr[ans_two] << " " << arr[ans_three];
                return 0;
            }
        }
    }

    cout << arr[ans_one] << " " << arr[ans_two] << " " << arr[ans_three];

    return 0;
}