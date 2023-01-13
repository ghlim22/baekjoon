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
    
    solve(start + 1, i);
    solve(i, end);
    cout << arr[start] << '\n';
    
}

signed main()
{
    fastio;
    int i = 0, temp;
    while (cin >> temp)
    {
        arr[i++] = temp;
    }
    solve(0, i);
    return 0;
}
