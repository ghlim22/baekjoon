#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_SIZE (100000)

static void multiply(char *multiplicand, char *multiplier, char *res);
static void convert_integer_to_arr(int num, char *arr);
static void print_num(char *num);
static void count_zeros(char *num);

static char multiplicand[100000] = {
    0,
};
static char multiplier[100000] = {
    0,
};
static char res[100000] = {
    0,
};

int main(int argc, char **argv)
{
    int N;

    scanf("%d", &N);
    convert_integer_to_arr(1, multiplicand);
    for (int i = 1; i <= N; ++i)
    {
        convert_integer_to_arr(i, multiplier);
        if (i % 2)
        {
            memset(res, 0x00, sizeof(char) * MAX_SIZE);
            multiply(multiplicand, multiplier, res);
        }
        else
        {
            memset(multiplicand, 0x00, sizeof(char) * MAX_SIZE);
            multiply(res, multiplier, multiplicand);
        }
    }

    if (N % 2)
        count_zeros(res);
    else
        count_zeros(multiplicand);

    return (0);
}

static void count_zeros(char *num)
{
    int cnt = 0;
    while (!num[cnt])
        cnt++;
    printf("%d\n", cnt);
}

static void print_num(char *num)
{
    int i = 0;
    while (num[i] != -1)
        i++;
    while (--i != -1)
        printf("%d", (int)num[i]);
    printf("\n");
}

static void convert_integer_to_arr(int num, char *arr)
{
    int i;

    if (num == 0)
    {
        arr[0] = 0;
        arr[1] = -1;
        return;
    }

    for (i = 0; num > 0; ++i)
    {
        arr[i] = num % 10;
        num /= 10;
    }
    arr[i] = -1;
}

static void multiply(char *multiplicand, char *multiplier, char *res)
{
    int i, j, pos, tmp_carry, tmp, tmp2;

    for (i = 0; multiplier[i] != -1; ++i)
    {
        pos = i;
        tmp_carry = 0;
        tmp = 0;
        for (j = 0; multiplicand[j] != -1; ++j)
        {
            tmp = tmp_carry + multiplier[i] * multiplicand[j];
            if (tmp >= 10)
            {
                tmp_carry = tmp / 10;
                tmp %= 10;
            }
            else
            {
                tmp_carry = 0;
            }
            tmp2 = res[pos + j] + tmp;
            if (tmp2 >= 10)
            {
                res[pos + j + 1] += tmp2 / 10;
                tmp2 %= 10;
            }
            res[pos + j] = tmp2;
        }
        if (tmp_carry > 0)
            res[pos + j] += tmp_carry;
    }

    if (res[pos + j] >= 10)
    {
        res[pos + j + 1] = res[pos + j] / 10;
        res[pos + j] %= 10;
        res[pos + j + 2] = -1;
    }
    else if (res[pos + j] == 0)
        res[pos + j] = -1;
    else
        res[pos + j + 1] = -1;
}
