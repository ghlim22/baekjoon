//https://www.acmicpc.net/problem/1158
//1158

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[])
{
    int N, K;
    cin >> N >> K;
    
    queue<int> q;
    
    for (int i = 1; i <= N; ++i)
    {
        q.push(i);
    }
    
    cout << "<";
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; ++i)
        {
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
            else
            {
                break;
            }
        }
        
        if (!q.empty())
        {
            cout << q.front();
            q.pop();
            if (q.empty())
            {
                cout << ">";
            }
            else
            {
                cout << ", ";
            }
        }
    }
    
    return 0;
}
