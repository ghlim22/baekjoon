// https://www.acmicpc.net/problem/10815
// 10815번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

int binary_search_left(int start, int end, int key, int cards[]);
int binary_search_right(int start, int end, int key, int cards[]);

int N, M;

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
    int cards[N + 2];

    for (int i = 1; i < N + 1; ++i)
    {
        cin >> cards[i];
    }
    cards[0] = INF;
    cards[N + 1] = -INF;

    sort(cards, cards + N + 2);

    cin >> M;

    while (M--)
    {
        int tmp;
        cin >> tmp;
        int i = binary_search_left(0, N + 1, tmp, cards);
        int j = binary_search_right(0, N + 1, tmp, cards);

        int cnt = (j - i + 1) > 0 ? 1 : 0;

        cout << cnt << " ";
    }

    return 0;
}

// 동일한 원소가 여러 개 있다면 가장 왼쪽에 위치한 원소의 인덱스 반환.
// 찾는 값이 배열에 없다면 그보다 큰 원소 중 가장 왼쪽 원소의 인덱스 반환.
int binary_search_left(int start, int end, int key, int cards[])
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (cards[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

// 동일한 원소가 여러 개 있다면 가장 오른쪽에 위치한 원소의 인덱스 반환.
// 찾는 값이 배열에 없다면 그보다 작은 원소 중 가장 오른쪽 원소의 인덱스 반환.
int binary_search_right(int start, int end, int key, int cards[])
{
    while (start < end)
    {
        int mid = (start + end + 1) / 2;
        if (cards[mid] <= key)
        {
            start = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}