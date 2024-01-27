#include <stdio.h>

#define MAX_SIZE (10000)
char buffer[MAX_SIZE][MAX_SIZE];

void solve(int n, int r, int c)
{
    if (n == 3) {
        buffer[r][c] = '*';
        buffer[r + 1][c - 1] = '*';
        buffer[r + 1][c + 1] = '*';
        buffer[r + 2][c - 2] = '*';
        buffer[r + 2][c - 1] = '*';
        buffer[r + 2][c] = '*';
        buffer[r + 2][c + 1] = '*';
        buffer[r + 2][c + 2] = '*';
        return;
    }
    solve(n / 2, r, c);
    solve(n / 2, r + n / 2, c - n / 2);
    solve(n / 2, r + n / 2, c + n / 2);
}

void print(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            printf("%c", buffer[i][j]);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
}

int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            buffer[i][j] = ' ';
        }
    }
    solve(n, 0, n - 1);
	print(n);

    return 0;
}
