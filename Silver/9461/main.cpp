//https://www.acmicpc.net/problem/9461
//파도반 수열

#include <iostream>
using namespace std;

long dt[101];

int main(int argc, const char * argv[])
{
    int count;
    
    dt[0] = 1;
    dt[1] = 1;
    dt[2] = 1;
    dt[3] = 2;
    dt[4] = 2;
    dt[5] = 3;
    dt[6] = 4;
    dt[7] = 5;
    dt[8] = 7;
    dt[9] = 9;
    
    cin >> count;
    
    for (int i = 0; i < count; ++i)
    {
        int num;
        cin >> num;
        
        for (int j = 10; j < num; ++j)
        {
            dt[j] = dt[j - 1] + dt[j - 5];
        }
        
        cout << dt[num - 1] << "\n";
    }
    
    return 0;
}
