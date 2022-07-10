//https://www.acmicpc.net/problem/11726
//2xn타일링

#include <iostream>
#define MAX (1000)
#define MODULAR (10007)

using namespace std;

int dt[MAX + 1];

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;

    dt[0] = 1;
    dt[1] = 2;
    
    for (int i = 2; i < n; ++i)
    {
        dt[i] = dt[i - 1] + dt[i - 2];
        dt[i] = dt[i] % MODULAR;
    }
    
    cout << dt[n - 1];
    
    return 0;
}
