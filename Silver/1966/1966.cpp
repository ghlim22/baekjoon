// https://www.acmicpc.net/problem/1966
// 1966번

//#include <bits/stdc++.h>
#include <deque>
#include <iostream>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int papers[100];

typedef struct
{
    int priority;
    int initial_idx;
} Paper;

void solve()
{
}

signed main()
{
    fastio;
    solve();

    int test_cnt, paper_cnt, target_idx, cnt;

    cin >> test_cnt;

    while (test_cnt-- > 0)
    {
        int idx = 0;
        cin >> paper_cnt >> target_idx;

        Paper papers[paper_cnt];
        deque<Paper> qe;

        for (int i = 0; i < paper_cnt; ++i)
        {
            Paper temp;
            cin >> temp.priority;
            temp.initial_idx = idx++;
            qe.push_back(temp);
        }
        cnt = 0;
        while (!qe.empty())
        {
            Paper temp = qe.front();
            bool canPrint = true;
            for (int i = 1; i < qe.size(); ++i)
            {
                if (qe[i].priority > temp.priority)
                {
                    qe.pop_front();
                    qe.push_back(temp);
                    canPrint = false;
                    break;
                }
            }

            if (canPrint)
            {
                cnt++;
                if (qe.front().initial_idx == target_idx)
                {
                    break;
                }
                qe.pop_front();
            }
        }

        cout << cnt << "\n";
    }
}