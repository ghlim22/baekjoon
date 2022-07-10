//
//  main.cpp
//  8979
//
//  Created by 임규현 on 2022/07/09.
//

#include <iostream>
#include <algorithm>
#define MEDAL_CNT (3)

using namespace std;

typedef struct
{
    int gold;
    int silver;
    int bronze;
    int rank;
    int num;
}Country;

bool compare_country(const Country &a, const Country &b)
{
    if (a.gold == b.gold)
    {
        if (a.silver == b.silver)
        {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int country_cnt;
    cin >> country_cnt;
    int target_num;
    cin >> target_num;
    
    Country arr[country_cnt];
    for (int i = 0; i < country_cnt; ++i)
    {
        cin >> arr[i].num >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
    }
    
    sort(arr, arr + country_cnt, compare_country);
    int rank = 1;
    arr[0].rank = rank;
    for (int i = 1; i < country_cnt; ++i)
    {
        
        if (arr[i - 1].gold == arr[i].gold && arr[i - 1].silver == arr[i].silver && arr[i - 1].bronze == arr[i].bronze)
        {
            arr[i].rank = rank;
        }
        else
        {
            rank = i + 1;
            arr[i].rank = rank;
        }
    }
    
    for (int i  = 0; i < country_cnt; ++i)
    {
        if (arr[i].num == target_num)
        {
            cout << arr[i].rank << "\n";
        }
    }
    
    return 0;
}
