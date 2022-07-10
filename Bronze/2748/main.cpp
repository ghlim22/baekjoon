#include <iostream>
using namespace std;

int N;
long dt[91];

long GetFibonacciRecursive(int N)
{
    if (N == 0)
    {
        return 0;
    }
    
    if (N == 1)
    {
        return 1;
    }
    
    if (dt[N] != -1)
    {
        return dt[N];
    }
    
    return dt[N] = GetFibonacciRecursive(N - 1) + GetFibonacciRecursive(N - 2);
}

int main(int argc, const char * argv[])
{
    cin >> N;
    
    fill(dt, dt + N + 1, -1);
    dt[0] = 0;
    dt[1] = 1;
    
    GetFibonacciRecursive(N);
    
    cout << dt[N] << '\n';
    
    return 0;
}
