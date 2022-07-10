//
//  main.cpp
//  1427
//
//  Created by 임규현 on 2022/07/09.
//

#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int digits[10];
    
    memset(digits, 0, sizeof(digits));
    
    int n;
    cin >> n;
    
    while (n > 0)
    {
        digits[n % 10]++;
        n /= 10;
    }
    
    for (int i = 9; i >= 0; --i)
    {
        for (int j = 0; j < digits[i]; ++j)
        {
            cout << i;
        }
    }
    return 0;
}
