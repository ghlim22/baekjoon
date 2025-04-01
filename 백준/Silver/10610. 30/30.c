#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

static bool check(int *digits)
{
    if (digits[0] == 0)
        return (false);
    long sum = 0;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < digits[i]; ++j)
            sum += i;
    }
    return ((sum % 3 == 0) ? true : false);
}

int main(void)
{
    int digits[10] = {0, };
    int c;

    while (1)
    {
        c = getc(stdin);
        if (isdigit(c))
            digits[c - '0']++;
        else
            break ;
    }
    if (check(digits))
    {
        for (int i = 9; i >= 0; --i)
        {
            for (int j = 0; j < digits[i]; ++j)
                printf("%d", i);
        }
    }
    else
    {
        printf("%d", -1);
    }
    return (0);
}