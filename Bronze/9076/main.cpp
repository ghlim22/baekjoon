//
//  main.cpp
//  9076
//
//  Created by 임규현 on 2022/07/08.
//

#include <iostream>
#define JUDGE_CNT (5)
using namespace std;

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int scores[JUDGE_CNT];
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < JUDGE_CNT; ++j)
        {
            cin >> scores[j];
        }
        for (int k = 0; k < JUDGE_CNT - 1; ++k)
        {
            for (int l = k + 1; l < JUDGE_CNT; ++l)
            {
                if (scores[k] > scores[l])
                {
                    scores[k] ^= scores[l];
                    scores[l] ^= scores[k];
                    scores[k] ^= scores[l];
                }
            }
        }
        if (scores[3] - scores[1] >= 4)
        {
            cout << "KIN\n";
        }
        else
        {
            cout << scores[3] + scores[2] + scores[1] << "\n";
        }
    }
    
    return 0;
}
