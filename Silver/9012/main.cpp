//https://www.acmicpc.net/problem/9012
//괄호 문제

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int testCount;
    bool isVPS;
    
    cin >> testCount;
    
    string str;
    
    
    while (testCount--)
    {
        cin >> str;
        isVPS = true;
        stack<int> stk; // 새로운 줄마다 스택을 새로 만들어줌.
        
        for (auto &ch : str)
        {
            if (ch == '(')
            {
                stk.push(1);
            }
            else
            {
                if (stk.empty()) // 스택이 비어있다면 vps가 아니다.
                {
                    isVPS = false;
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        
        if (isVPS && stk.empty())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        
    }
    
    return 0;
}
