#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int houses[200000];

signed main()
{
    fastio;

    int house_cnt = 0;
    int router_cnt = 0;

    cin >> house_cnt >> router_cnt;
    for (int i = 0; i < house_cnt; ++i)
        cin >> houses[i];
    sort(houses, houses + house_cnt);
    int left = 1;
    int right = (houses[house_cnt - 1] - houses[0] + 1) / (router_cnt - 1);
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cur = 0;
        int cnt = 1;
        for (int i = 1; i < house_cnt; ++i)
        {
            if (houses[i] - houses[cur] >= mid)
            {
                cur = i;
                cnt++;
            }
            if (cnt >= router_cnt)
                break ;
        }
        if (cnt >= router_cnt)
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;

    return 0;
}
