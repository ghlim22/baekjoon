#include <stdio.h>

#define SWAP(x, y)                                                             \
    do {                                                                       \
        int tmp = x;                                                           \
        x = y;                                                                 \
        y = tmp;                                                               \
    } while (0)

int n;
int m;
int input[8] = {
    0,
};
int vis[8] = {
    0,
};
int print[8] = {
    0,
};

void sort(int start, int end);
void solve(int dep);

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input[i]);
    }
    sort(0, n - 1);
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", input[i]);
    // }
    // printf("\n");
    solve(0);

    return 0;
}

void sort(int start, int end)
{
    int left = start;
    int right = end;
    int pivot = input[(start + end) / 2];

    do {
        while (left <= end && input[left] < pivot) {
            ++left;
        }
        while (right >= start && input[right] > pivot) {
            --right;
        }
        if (left <= right) {
            SWAP(input[left], input[right]);
            ++left;
            --right;
        }
    } while (left <= right);

    if (start < right) {
        sort(start, right);
    }
    if (left < end) {
        sort(left, end);
    }
}

void solve(int dep)
{
    if (dep == m) {
        for (int i = 0; i < m; ++i) {
            printf("%d", print[i]);
            if (i < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && (input[i] != last)) {
            vis[i] = 1;
            last = input[i];
            print[dep] = input[i];
            solve(dep + 1);
            vis[i] = 0;
        }
    }
}