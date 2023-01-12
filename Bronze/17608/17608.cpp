#include <iostream>
#include <stack>

using namespace std;

signed main(void)
{
    stack<int> st;
    int stick_count = 0;
    int current_tallest = 0;
    int ans = 0;

    cin >> stick_count;
    for (int i = 0; i < stick_count; ++i)
    {
        int input;
        cin >> input;
        st.push(input);
    }
    for (int i = 0; i < stick_count; ++i)
    {
        int tmp = st.top();
        st.pop();
        if (tmp <= current_tallest)
            continue;
        ans++;
        current_tallest = tmp;
    }
    cout << ans;

    return (0);
}