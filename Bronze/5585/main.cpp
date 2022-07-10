//https://www.acmicpc.net/problem/5585
//거스름돈

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int bill, total = 0, count = 0;
    cin >> bill;
    total = 1000 - bill;
    
    count += total / 500;
    total %= 500;
    count += total / 100;
    total %= 100;
    count += total / 50;
    total %= 50;
    count += total / 10;
    total %= 10;
    count += total / 5;
    total %= 5;
    count += total;
    
    cout << count;
    
    
    return 0;
}
