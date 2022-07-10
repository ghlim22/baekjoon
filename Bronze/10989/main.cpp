//
//  main.cpp
//  10989
//
//  Created by 임규현 on 2022/07/08.
//

#include <iostream>
using namespace std;

int nums[10001];

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    int n;
    cin >> n;
    
    int idx;
    for (int i = 0; i < n; ++i)
    {
        cin >> idx;
        nums[idx]++;
    }
    for (int i = 0; i < 10001; ++i)
    {
        if (nums[i] > 0)
        {
            for (int j = 0; j < nums[i]; ++j)
            {
                cout << i << "\n";
                cnt++;
            }
        }
        if (cnt == n)
        {
            break;
        }
    }
    
    return 0;
}
