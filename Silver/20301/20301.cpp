#include <deque>
#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque<int> dq;
    deque<int>::iterator iter;

    int n, k, m, cnt = 0;
    bool isReverse = false;

    cin >> n >> k >> m;

    for (int i = 1; i <= n; ++i)
    {
        dq.push_back(i); // initialize.
    }

    while (cnt < n)
    {
        if (cnt > 0 && cnt % m == 0)
        {
            isReverse = !isReverse; // reverse.
        }

        if (!isReverse)
        {
            for (int i = 0; i < k - 1; ++i)
            {
                if (!dq.empty())
                {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
                else
                {
                    break;
                }
            }

            if (!dq.empty())
            {
                cout << dq.front();
                dq.pop_front();
                cnt++;
            }
        }
        else
        {
            for (int i = 0; i < k - 1; ++i)
            {
                if (!dq.empty())
                {
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
                else
                {
                    break;
                }
            }
            if (!dq.empty())
            {
                cout << dq.back();
                dq.pop_back();
                cnt++;
            }
        }
        cout << "\n";
    }

    return 0;
}