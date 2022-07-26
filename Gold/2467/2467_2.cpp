// https://www.acmicpc.net/problem/2467
// 2467번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define GET_ABSOLTUE_VAL(x) ((x) >= 0 ? (x) : -(x))

int N;
int arr[100001];

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
    int ans_one;
    int ans_two;
    int left = 0;
    int right = N - 1;
    int sum = INT32_MAX;
    while (left < right)
    {
        int temp = arr[left] + arr[right];
        if (abs(temp) <= abs(sum))
        {
            ans_one = left;
            ans_two = right;
            sum = temp;
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
            break;
        }
    }

    cout << arr[ans_one] << " " << arr[ans_two];

    return 0;
}