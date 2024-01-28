
#include <cmath>
#include <cstdio>
int g_input_arr[9][9];
long long g_result = -1;
int n;
int m;

static void input()
{
    std::scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::scanf("%1d", &g_input_arr[i][j]);
        }
    }
}

static bool is_perfect_square_number(long long num)
{
    if (num == 0) {
        return true;
    }
    long long k = (long long)std::sqrt(num);
    return (k * k == num);
}

static inline bool is_valid_range(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}

static void search(int r, int c, long long num, int r_cd, int c_cd)
{
    if (!is_valid_range(r, c)) {
        return;
    }
    num = num * 10 + g_input_arr[r][c];
    if (is_perfect_square_number(num) && num > g_result) {
        g_result = num;
    }
    int nr = r + r_cd;
    int nc = c + c_cd;
    if (is_valid_range(nr, nc)) {
        search(nr, nc, num, r_cd, c_cd);
    }
}

static void solve(int r, int c)
{
    long long num = g_input_arr[r][c];
    if (is_perfect_square_number(num) && num > g_result) {
        g_result = num;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int rcd_pos = i;
            int rcd_neg = -i;
            int ccd_pos = j;
            int ccd_neg = -j;
            if (is_valid_range(r + rcd_pos, c + ccd_pos)) {
                search(r + rcd_pos, c + ccd_pos, num, rcd_pos, ccd_pos);
            }
            if (is_valid_range(r + rcd_pos, c + ccd_neg)) {
                search(r + rcd_pos, c + ccd_neg, num, rcd_pos, ccd_neg);
            }
            if (is_valid_range(r + rcd_neg, c + ccd_pos)) {
                search(r + rcd_neg, c + ccd_pos, num, rcd_neg, ccd_pos);
            }
            if (is_valid_range(r + rcd_neg, c + ccd_neg)) {
                search(r + rcd_neg, c + ccd_neg, num, rcd_neg, ccd_neg);
            }
        }
    }
}

int main(void)
{
    input();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            solve(i, j);
        }
    }
    std::printf("%lld\n", g_result);
    return 0;
}