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
    int mid; // 중간 거리.
    int cur; // 공유기를 설치한 위치.
    int ans = 0; // 답.

    while (left <= right)
    {
        cnt = 1; // 공유기 1개 설치.
        mid = (left + right) / 2; // 중간 거리 구하기.
        cur = 0; // 공유기를 설치한 기준 좌표의 인덱스.
        for (int i = 1; i < N; ++i)
        {
            if (arr[i] - arr[cur] >= mid) // 기준 좌표와 비교 좌표의 거리 차가 mid 이상이면 공유기를 설치한다. 기준 좌표를 최신화한다.
            {
                cnt++;
                cur = i;
            }
        }
        if (cnt >= C) // 공유기를 c대 이상 설치했다면...
        {
            ans = mid; // 중간 거리를 정답에 저장한다.
            left = mid + 1; // 더 큰 거리를 탐색한다.
        }
        else
        {
            right = mid - 1; // 가능한 거리의 크기를 좁힌다.
        }
    }

    cout << ans;

    return 0;
}
