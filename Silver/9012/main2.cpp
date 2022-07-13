
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int testCount;
    bool isVPS;

    cin >> testCount;

    string s;

    while (testCount--)
    {
        cin >> s;
        isVPS = true;
        stack<int> stk;
        for (auto &c : s)
        {
            if (c == '(')
            {
                stk.push(1);
            }
            else if (stk.empty())
            {
                isVPS = false;
                break;
            }
            else
            {
                stk.pop();
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