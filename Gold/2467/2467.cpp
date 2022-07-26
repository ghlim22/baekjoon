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

int alkali_pnt, acid_lowerbound, alkali_upperbound, acid_upperbound, pivot_val, N;
int arr[100000];

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
        int temp;
        cin >> temp;
        if (temp > 0)
        {
            alkali_upperbound = i - 1;
        }
        arr[i] = temp;
    }

    pivot_val = GET_ABSOLTUE_VAL(arr[0] + arr[alkali_upperbound + 1]);
    alkali_pnt = 0;
    acid_lowerbound = alkali_upperbound + 1;
    acid_upperbound = N - 1;
    int ans_alkali = 0;
    int ans_acid = acid_lowerbound;
    int alkali_cnt = alkali_upperbound + 1;

    while (alkali_cnt--)
    {
        int right = acid_upperbound;
        int left = acid_lowerbound;
        while (left < right)
        {
            int mid = (left + right) / 2;
            int temp = GET_ABSOLTUE_VAL(arr[alkali_pnt] + arr[mid]);

            if (temp > pivot_val)
            {
                left = mid + 1;
            }
            else if (temp < pivot_val)
            {
                right = mid - 1;
                pivot_val = temp;
                ans_alkali = alkali_pnt;
                ans_acid = mid;
            }
        }
        alkali_pnt++;
    }

    cout << arr[ans_alkali] << " " << arr[ans_acid];

    return 0;
}