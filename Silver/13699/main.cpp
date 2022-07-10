//https://www.acmicpc.net/problem/13699
//점화식

#include <iostream>

using namespace std;

long dt[36];

int main(int argc, const char * argv[])
{
    int n;
    dt[0] = 1; // 초기 조건.
    
    cin >> n;
    
    for (int i = 1; i <= n; ++i)
    {
        long sum = 0;
        int idx = 0;
        for (int j = i - 1; j >= 0; --j)
        {
            sum += dt[idx++] * dt[j];
        }
        
        dt[i] = sum;
    }
    
    cout << dt[n] << "\n";
    
    return 0;
}
