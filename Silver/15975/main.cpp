//
//  main.cpp
//  15975
//
//  Created by 임규현 on 2022/07/08.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
    int idx;
    int color;
}Dot;

bool compare_dot(const Dot &a, const Dot &b)
{
    if (a.color == b.color)
    {
        return a.idx < b.idx;
    }
    
    return a.color < b.color;
}

Dot dots[100001];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long len = 0;
        
    for (int i = 0; i < n; ++i)
    {
        cin >> dots[i].idx >> dots[i].color;
    }
    
    sort(dots, dots + n, compare_dot);
    
    for (int i = 0; i < n; ++i)
    {
        /*
        //왼쪽 탐색.
        long long left_len = 0;
        for (int j = i - 1; j >= 0; --j)
        {
            if (dots[i].color == dots[j].color)
            {
                left_len += (dots[i].idx - dots[j].idx);
                break;
            }
        }
        
        //오른쪽 탐색.
        long long right_len = 0;
        for (int j = i + 1; j < n; ++j)
        {
            if (dots[i].color == dots[j].color)
            {
                right_len += (dots[j].idx - dots[i].idx);
                break;
            }
        }
        */
        int left_len = 0;
        int right_len = 0;
        if (i == 0)
        {
            if (dots[i].color == dots[i + 1].color)
            {
                len += dots[i + 1].idx - dots[i].idx;
            }
        }
        else if (i == n - 1)
        {
            if (dots[i - 1].color == dots[i].color)
            {
                len += dots[i].idx - dots[i - 1].idx;
            }
        }
        else
        {
            if (dots[i].color == dots[i - 1].color)
            {
                left_len += dots[i].idx - dots[i - 1].idx;
            }
            
            if (dots[i].color == dots[i + 1].color)
            {
                right_len += dots[i + 1].idx - dots[i].idx;
            }
        }
        
        if (left_len == 0)
        {
            if (right_len > 0)
            {
                len += right_len;
            }
        }
        else
        {
            if (right_len == 0)
            {
                len += left_len;
            }
            else
            {
                len += (left_len < right_len) ? left_len : right_len;
            }
        }
         
    }
    
    cout << len;
    
    return 0;
}
