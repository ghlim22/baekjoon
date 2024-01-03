#include <algorithm>
#include <iostream>

int array[20][20];

int main(void)
{
    int n;
    int cases;
    int ans = __INT32_MAX__;


/* Get inputs */
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char c;

            std::cin >> c;
            if (c == 'H')
                array[i][j] = 1;
        }
    }

    cases = 1 << n;
    for (int mask = 0; mask < cases; ++mask)
    {
        int current_tail = 0;
        for (int col = 0; col < n; ++col)
        {
            int column_tail = 0;
            for (int row = 0; row < n; ++row)
            {
                if (1 & (mask >> row)) /* Flip the row */
                {
                    if (!array[row][col])
                        ++column_tail;
                }
                else if (array[row][col])
                    ++column_tail;
            }
            /* Filp the current column or don't */
            current_tail += std::min(column_tail, n - column_tail);
        }
        ans = std::min(current_tail, ans);
    }

    std::cout << ans << std::endl;

    return 0;
}
