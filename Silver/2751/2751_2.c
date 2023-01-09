#include <stdio.h>

static int negetive_nums[1000000];
static int nums[1000001]; // including 0.

int main(void)
{
    int n_count = 0;
    int p_count = 0;
    int negative_printed = 0;
    int positive_printed = 0;
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        int input;
        scanf("%d", &input);
        if (input >= 0)
        {
            nums[input]++;
            p_count++;
        }
        else
        {
            negetive_nums[-input]++;
            n_count++;
        }
    }
    for (int i = 1000000; i > 0; --i)
    {
        if (negetive_nums[i])
        {
            for (int j = 0; j < negetive_nums[i]; ++j)
            {
                printf("%d\n", -i);
                negative_printed++;
            }
            if (negative_printed == n_count)
                break ;
        }
        
    }
    for (int i = 0; i <= 1000000; ++i)
    {
        if (nums[i])
        {
            for (int j = 0; j < nums[i]; ++j)
            {
                printf("%d\n", i);
                positive_printed++;
            }
            if (positive_printed == p_count)
                break ;
        }
        
    }
    return (0);
}