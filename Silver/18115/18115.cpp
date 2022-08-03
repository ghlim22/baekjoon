// https://www.acmicpc.net/problem/18115
// 18115번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N;
int actions[1000000];
deque<int> cards_in_hand;

void solve()
{
    for (int i = 0; i < N; ++i)
    {
        switch (actions[N - i - 1])
        {
        case 1:
            cards_in_hand.push_front(i + 1);
            break;
        case 2:
            if (cards_in_hand.empty())
            {
                cards_in_hand.push_front(i + 1);
            }
            else
            {
                cards_in_hand.insert(cards_in_hand.begin() + 1, i + 1);
            }
            break;
        case 3:
            cards_in_hand.push_back(i + 1);
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << cards_in_hand.at(i) << (i == N - 1 ? "" : " ");
    }
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> actions[i];
    }
    solve();
}