// https://www.acmicpc.net/problem/1083
// 1083번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
unsigned int N, S;
unsigned int arr[50];

unsigned int find_max_idx(unsigned int start, unsigned int end)
{
    unsigned int max = 0;
    unsigned int max_idx = 0;
    if (end > N - 1)
    {
        end = N - 1;
    }
    for (int i = start; i <= end; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
            max_idx = i;
        }
    }

    return max_idx;
}

void solve()
{
    unsigned int start = 0;
    while (S)
    {
        bool is_sorted = true;
        unsigned int max_idx = find_max_idx(start, start + S); // 교환 가능한 범위 내 최대 값을 찾는다.
        for (int i = max_idx; i > start; --i)                  // 가장 큰 원소를 start 위치로 가져온다.
        {
            if (arr[i] > arr[i - 1])
            {
                unsigned int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                S--;
                is_sorted = false;
            }
            if (S == 0) // 추가적인 교환이 불가능하면 반복문을 탈출한다.
            {
                break;
            }
        }

        if (is_sorted && (start != max_idx)) // 정렬이 완료된 경우 반복문을 탈출한다. 가장 큰 원소가 start에 위치해서 for문이 실행되지 않는 경우는 제외한다.
        {
            break;
        }

        start++;
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    cin >> S;
    solve();
    for (int i = 0; i < N; ++i)
    {
        cout << arr[i];
        cout << (i == N - 1 ? "" : " ");
    }

    return 0;
}