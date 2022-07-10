#include <stdio.h>
#define min(a, b) a < b ? a : b
#define MAX (50)

int main(void)
{
    char board[MAX][MAX];
    int row, col, cntW, cntB, cnt_min = 64;

    scanf("%d%d", &row, &col);
    getchar();

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            board[i][j] = getchar();
        }
        getchar();
    }

    for (int i = 0; i < row - 7; ++i)
    {
        for (int j = 0; j < col - 7; ++j)
        {
            cntW = 0;
            cntB = 0;

            for (int k = i; k < i + 8; ++k)
            {
                for (int l = j; l < j + 8; ++l)
                {
                    if ((k + l) % 2 == 0)
                    {
                        if (board[k][l] == 'B')
                        {
                            cntW++;
                        }
                        else
                        {
                            cntB++;
                        }
                    }
                    else
                    {
                        if (board[k][l] == 'B')
                        {
                            cntB++;
                        }
                        else
                        {
                            cntW++;
                        }
                    }
                }
            }

            cnt_min = min(cnt_min, cntW);
            cnt_min = min(cnt_min, cntB);
        }
    }

    printf("%d\n", cnt_min);

    return 0;
}