// https://www.acmicpc.net/problem/1918
// 1918번

#include <iostream>
#include <stack>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
cout << fixed;   \
cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve()
{
}

bool is_higher_precedence(char x, char y) // x가 y보다 높거나 같은 우선순위인가??
{
    if (x == '(') // '('를 output에 넣는 것 방지.
    {
        return false;
    }
    if (y == '*' || y == '/')
    {
        if (x == '+' || x == '-')
        {
            return false;
        }
        return true;
    }
    return true;
}

signed main()
{
    fastio;
    
    deque<char> output;
    deque<char>::iterator iter;
    stack<char> opstack;
    char ch, temp;
    
    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'A' && ch <= 'Z') // 피연산자가 나오면 output에 넣어준다.
        {
            output.push_back(ch);
        }
        else if (ch == '(') // '('가 나오면 opstack에 쌓은다.
        {
            opstack.push(ch);
        }
        else if (ch == ')') // ')'가 나오면 대응하는 '('가 나올 때까지 opstak의 연산자를 output에 넣어준다.
        {
            while (!opstack.empty() && (temp = opstack.top()) != '(')
            {
                output.push_back(temp);
                opstack.pop();
            }
            opstack.pop(); // '('를 제거한다.
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!opstack.empty() && is_higher_precedence(opstack.top(), ch))
            {
                output.push_back(opstack.top());
                opstack.pop();
            }
            
            opstack.push(ch);
        }
    }
    
    while (!opstack.empty())
    {
        output.push_back(opstack.top());
        opstack.pop();
    }
    
    while (!output.empty())
    {
        cout << output.front();
        output.pop_front();
    }
    
    return 0;
}
