//
//  main.cpp
//  2822
//
//  Created by 임규현 on 2022/07/09.
//

#include <iostream>
#include <algorithm>

#define QUIZ_NUM (8)

using namespace std;

typedef struct
{
    int score;
    int idx;
}Quiz;

bool compare_quiz_score(const Quiz &a, const Quiz &b)
{
    return a.score < b.score;
}

bool compare_quiz_idx(const Quiz &a, const Quiz &b)
{
    return a.idx < b.idx;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    Quiz arr[QUIZ_NUM];
    
    for (int i = 0; i < QUIZ_NUM; ++i)
    {
        cin >> arr[i].score;
        arr[i].idx = i + 1;
    }
    
    sort(arr, arr + QUIZ_NUM, compare_quiz_score);
    
    int sum = 0;
    for (int i = 3; i < QUIZ_NUM; ++i)
    {
        sum += arr[i].score;
    }
    
    cout << sum << "\n";
    
    sort(arr + 3, arr + QUIZ_NUM, compare_quiz_idx);
    
    for (int i = 3; i < QUIZ_NUM; ++i)
    {
        cout << arr[i].idx << " ";
    }
    
    return 0;
}
