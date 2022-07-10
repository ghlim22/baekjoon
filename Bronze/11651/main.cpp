//
//  main.cpp
//  11651
//
//  Created by 임규현 on 2022/07/08.
//

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int x;
    int y;
}Dot;

bool compare_dot(Dot a, Dot b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }
    
    return a.y < b.y;
}


int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    Dot arr[n];
    
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    
    sort(arr, arr + n, compare_dot);
    
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].x << " " <<arr[i].y << "\n";
    }
    
    return 0;
}
