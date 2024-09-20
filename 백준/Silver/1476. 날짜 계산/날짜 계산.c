#include <stdio.h>

int main(void)
{
    int e;
    int s;
    int m;
    int i;

    scanf("%d %d %d", &e, &s, &m);

    i = 0;
    while (1) {
        ++i;
        if ((i - e) % 15 != 0)
            continue;
        if ((i - s) % 28 != 0)
            continue;
        if ((i - m) % 19 != 0)
            continue;
        printf("%d\n", i);
        break;
    }

    return 0;
}