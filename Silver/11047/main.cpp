// https://www.acmicpc.net/problem/11047
// 동전 0

#include <iostream>
using namespace std;

int N, K, ans, coins[10];

void solve(int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        ans += K / coins[i];
        K %= coins[i];
    }
}

int main(int argc, const char * argv[])
{
    cin >> N >> K;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }
    
    solve(N);
    
    cout << ans;
    
    return 0;
}
