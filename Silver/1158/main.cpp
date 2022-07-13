// https://www.acmicpc.net/problem/1158
// 1158
//요세푸스 순열

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char *argv[])
{
    queue<int> q;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        q.push(i);
    }

    if (k > n)
    {
        k %= n;
    }

    cout << "<";
    for (int i = 0; i < n; ++i)
    {
        // k - 1 번째 사람까지 앞에서 빼준 뒤 다시 뒤에 넣어준다.
        for (int j = 0; j < k - 1; ++j)
        {
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
        int temp = q.front();
        q.pop();
        cout << temp;
        if (i != n - 1)
        {
            cout << ", ";
        }
    }
    cout << ">";

    return 0;
}
