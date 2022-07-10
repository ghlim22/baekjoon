// 20301
// 반전 요세푸스 순열
#include <iostream>
#include <deque>
using namespace std;

int main(int argc, const char * argv[])
{
    int N, K, M;
    cin >> N >> K >> M;
    
    deque<int> dq;
    
    deque<int>::iterator iter;
    
    for (int i = 1; i <= N; ++i)
    {
        dq.push_back(i);
    }
    
    
    int count = 0;
    bool isReverse = false;
    
    while (!dq.empty())
    {
        if (count > 0 && count % M == 0)
        {
            isReverse = !isReverse;
        }
        
        if (!isReverse)
        {
            for (int i = 0; i < K - 1; ++i)
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
                cout << dq.front() << "\n";
                dq.pop_front();
                count++;
            }
        }
        else
        {
            for (int i = 0; i < K - 1; ++i)
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
                cout << dq.back() << "\n";
                dq.pop_back();
                count++;
                
            }
        }
    }
    
    return 0;
}
