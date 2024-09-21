#include <stdio.h>

int broken[10];

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int abs(int n) {
    if (n < 0)
        return -n;
    return n;
}

int press(int n) {
    int cnt = 0;
    do {
        if (broken[n % 10])
            return 0;
        n /= 10;
        ++cnt;
    } while (n > 0);
    
    return cnt;
}

int main(void)
{
    int n;
    int m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int num;
        scanf("%d", &num);
        broken[num] = 1;
    }

    int ans = abs(n - 100);
    if (m == 10) {
        goto EXIT;
    }

    for (int i = n; i >= 0; --i) {
        int p = press(i);
        if (p > 0) {
            ans = min(ans, p + n - i);
            break;
        }
    }

    for (int i = n; i < 1000000; ++i) {
        int p = press(i);
        if (p > 0) {
            ans = min(ans, p + i - n);
            break;
        }
    }

EXIT:
    printf("%d\n", ans);

    return 0;
}
