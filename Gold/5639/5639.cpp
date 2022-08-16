// https://www.acmicpc.net/problem/5639
// 5639번

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int arr[10000];

void solve(int start, int end)
{
    int i;
    if (start >= end)
    {
        return;
    }

    for (i = start + 1; i < end; ++i)
    {
        if (arr[start] < arr[i])
        {
            break;
        }
    }

    solve(start + 1, i);        // 왼쪽 자식 트리
    solve(i, end);              // 오른쪽 자식 트리
    cout << arr[start] << '\n'; // 현재 원소를 가장 마지막에 출력.
}

signed main()
{
    fastio;
    int input_num = 0;
    int input;

    while (cin >> input)
    {
        arr[input_num++] = input;
    }

    solve(0, input_num);

    return 0;
}
