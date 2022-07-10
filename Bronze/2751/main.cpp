#include <iostream>
using namespace std;

int nums[1000001];
int negative_nums[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; // 수의 개수.
    cin >> n;
    
    int positive_cnt = 0;
    int negative_cnt = 0;

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp >= 0)
        {
            nums[temp]++;
            positive_cnt++;
        }
        else
        {
            negative_nums[-temp]++;
            negative_cnt++;
        }
    }
    
    int cnt_n = 0;
    int cnt_p = 0;
    for (int i = 1000000; i >= 0; --i)
    {
        if (negative_nums[i] > 0)
        {
            for (int j = 0; j < negative_nums[i]; ++j)
            {
                cout << -i << "\n";
                cnt_n++;
            }
            if (cnt_n == negative_cnt)
            {
                break;
            }
        }
    }
    for (int i = 0; i < 1000001; ++i)
    {
        if (nums[i] > 0)
        {
            for (int j = 0; j < nums[i]; ++j)
            {
                cout << i << "\n";
                cnt_p++;
            }
        }
        if (cnt_p == positive_cnt)
        {
            return 0;
        }
    }
    
    return 0;
}
