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
bool check_row[BOARD_SIZE][BOARD_SIZE], check_col[BOARD_SIZE][BOARD_SIZE], check_square[BOARD_SIZE][BOARD_SIZE];

void solve(int count)
{
    if (81 == count) // 스도쿠 보드판을 다 돌았으면 출력 후 종료.
    {
        for (int i = 0; i < BOARD_SIZE; ++i)
        {
            for (int j = 0; j < BOARD_SIZE; ++j)
            {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    int row = count / 9;
    int col = count % 9;

    if (sudoku[row][col] == 0)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (!check_row[row][i] && !check_col[col][i] && !check_square[row / 3 * 3 + col / 3][i])
            {
                check_row[row][i] = true;
                check_col[col][i] = true;
                check_square[row / 3 * 3 + col / 3][i] = true;

                sudoku[row][col] = i + 1;

                solve(count + 1);

                sudoku[row][col] = 0; // 다음 함수 호출을 위해서 다시 0으로 돌려준다.

                check_row[row][i] = false;
                check_col[col][i] = false;
                check_square[row / 3 * 3 + col / 3][i] = false;
            }
            if (i == 8) // 숫자를 다 순회했으면 반환해준다.
            {
                return;
            }
        }
    }
    else
    {
        solve(count + 1); // 보드 판 위 수가 0이 아니면 그냥 다음 함수를 호출한다.
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
            if (temp != 0)
            {
                check_row[i][temp - 1] = true;
                check_col[j][temp - 1] = true;
                check_square[i / 3 * 3 + j / 3][temp - 1] = true;
            }
            sudoku[i][j] = temp;
        }
    }

    solve(0);

    return 0;
}
