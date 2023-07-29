#include <iostream>

static int  solve(int N, int r, int c);

int main(void)
{
    int N;
    int r;
    int c;

    std::cin >> N >> r >> c;
    std::cout << solve(N, r, c);

    return (0);
}

static int  solve(int N, int r, int c)
{
    if (N == 0)
        return 0;
    int len = 1 << N;
    int unit = 1 << (2 * N - 2); // len * len / 4;
    if (r < len / 2)
    {
        if (c < len / 2)
        {
            return solve(N - 1, r, c);
        }
        else
        {
            return unit + solve(N - 1, r, c - len / 2);
        }
    }
    else
    {
        if (c < len / 2)
        {
            return unit * 2 + solve(N - 1, r - len / 2, c);
        }
        else
        {
            return unit * 3 + solve(N - 1, r - len / 2, c - len / 2);
        }
    }
}
