// https://www.acmicpc.net/problem/1874
// 1874번

//#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <stack>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
cout << fixed;   \
cout.precision(x)

using namespace std;

static const int INF = 0x3f3f3f3f;

int n,idx, sequence[100001];
stack<int> s;
vector<char> result;

void solve()
{
}

signed main()
{
    fastio;
   
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> sequence[i];
    }
    
    idx = 0;
    for (int i = 1; i <= n; ++i)
    {
        s.push(i);
        result.push_back('+');
        
        while (!s.empty() && s.top() == sequence[idx])
        {
            s.pop();
            result.push_back('-');
            idx++;
        }
    }
    
    if (s.empty())
    {
        for (int i = 0, len = (int)result.size(); i < len; ++i)
        {
            cout << result[i] << "\n";
        }
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}

