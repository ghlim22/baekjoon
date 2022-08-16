// https://www.acmicpc.net/problem/1697
// 1697번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MIN_IDX (0)
#define MAX_IDX (100000)

using namespace std;

static const int INF = 0x3f3f3f3f;

int arr[MAX_IDX + 1];

int solve(int n, int k)
{
    if (n >= k)
    {
        return n - k;
    }

    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int front = q.front();
        if (front == k)
        {
            return arr[front];
        }
        if (front - 1 >= MIN_IDX && !arr[front - 1])
        {
            arr[front - 1] = arr[front] + 1;
            q.push(front - 1);
        }
        if (front + 1 <= MAX_IDX && !arr[front + 1])
        {
            arr[front + 1] = arr[front] + 1;
            q.push(front + 1);
        }
        if (front * 2 <= MAX_IDX && !arr[front * 2])
        {
            arr[front * 2] = arr[front] + 1;
            q.push(front * 2);
        }
        q.pop();
    }

    return 0;
}

signed main()
{
    fastio;
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}