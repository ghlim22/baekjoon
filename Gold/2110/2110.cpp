#include <iostream>
#include <algorithm>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

int arr[200000];
int N, C;

void solve()
{
}

signed main()
{
    fastio;

    // 집의 개수와 공유기 개수를 입력받고 좌표 입력받은 후 오름차순 정렬.
    cin >> N >> C;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    // 이진 탐색 활용.
    int left = 1;               // 최소 거리.
    int right = arr[N - 1] - 1; // 최대 거리.
    int cnt;                    // 설치한 공유기의 수.
    int mid;
    int cur; // 공유기를 설치한 위치.
    int ans = 0;

    while (left <= right)
    {
        cnt = 1;
        mid = (left + right) / 2;
        cur = 0;
        for (int i = 1; i < N; ++i)
        {
            if (arr[i] - arr[cur] >= mid)
            {
                cnt++;
                cur = i;
            }
        }
        if (cnt >= C)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}