// https://www.acmicpc.net/problem/2580
// 2580번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define BOARD_SIZE (9)

using namespace std;

static const int INF = 0x3f3f3f3f;

int sudoku[BOARD_SIZE][BOARD_SIZE];
int zero_cnt = 0;

int get_division(int row, int col)
{
    int division;
    if (row <= 2)
    {
        if (col <= 2)
        {
            division = 0;
        }
        else if (col <= 5)
        {
            division = 1;
        }
        else
        {
            division = 2;
        }
    }
    else if (row <= 5)
    {
        if (col <= 2)
        {
            division = 3;
        }
        else if (col <= 5)
        {
            division = 4;
        }
        else
        {
            division = 5;
        }
    }
    else
    {
        if (col <= 2)
        {
            division = 6;
        }
        else if (col <= 5)
        {
            division = 7;
        }
        else
        {
            division = 8;
        }
    }

    return division;
}

bool row_check(int row, int num)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (sudoku[row][i] == num)
        {
            return true; // 중복되면 true.
        }
    }
    return false;
}

bool col_check(int col, int num)
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        if (sudoku[i][col] == num)
        {
            return true; // 중복되면 true.
        }
    }
    return false;
}

bool square_check(int row, int col, int num)
{
    int division = get_division(row, col);
    int start_row = (division / 3) * 3;
    int start_col = (division % 3) * 3;

    for (int i = start_row; i < start_row + 3; ++i)
    {
        for (int j = start_col; j < start_col + 3; ++j)
        {
            if (sudoku[i][j] == num)
            {
                return true; // 중복되면 true.
            }
        }
    }
    return false;
}

void solve(int row, int col)
{
    /*
    if (zero_cnt == 0)
    {
        return;
    }
    */

    for (int i = 1; i <= 9; ++i)
    {
        if (!row_check(row, i) && !col_check(col, i) && !square_check(row, col, i))
        {
            sudoku[row][col] = i;
            zero_cnt--;
            break;
        }
    }
}

signed main()
{
    fastio;
    int temp;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            cin >> temp;
            if (temp == 0)
            {
                zero_cnt++;
            }
            sudoku[i][j] = temp;
        }
    }

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (sudoku[i][j] == 0)
            {
                solve(i, j);
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}