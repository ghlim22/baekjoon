//
//  main.cpp
//  5800
//
//  Created by 임규현 on 2022/07/09.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool compare_descend(int &a, int &b)
{
    return a > b;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int class_cnt;
    cin >> class_cnt;
    
    for (int i = 0; i < class_cnt; ++i)
    {
        int student_cnt;
        cin >> student_cnt;
        int scores[student_cnt];
        for (int j = 0; j < student_cnt; ++j)
        {
            cin >> scores[j];
        }
        sort(scores, scores + student_cnt, compare_descend);
        int largest_gap = 0;
        for (int j = 0; j < student_cnt - 1; ++j)
        {
            int gap = scores[j] - scores[j + 1];
            if (gap > largest_gap)
            {
                largest_gap = gap;
            }
        }
        cout << "Class " << i + 1 << "\n";
        cout << "Max " << scores[0] << ", ";
        cout << "Min " << scores[student_cnt - 1] << ", ";
        cout << "Largest gap " << largest_gap << "\n";
        
    }
    return 0;
}
