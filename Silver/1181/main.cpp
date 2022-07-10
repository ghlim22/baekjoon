//
//  main.cpp
//  1181
//
//  Created by 임규현 on 2022/07/08.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare_word(const string &a, const string &b)
{
    int a_len = (int)a.length();
    int b_len = (int)b.length();
    
    if (a_len == b_len)
    {
        return a < b;
    }
    
    return a_len < b_len;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string arr[n];
    
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + n, compare_word);
    
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != arr[i + 1])
        {
            cout << arr[i];
            if (i < n - 1)
            {
                cout << "\n";
            }
        }
    }
    
    return 0;
}
