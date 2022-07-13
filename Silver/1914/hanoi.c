#include <stdio.h>

// https://daydreamx.tistory.com/entry/baekjoon1914
void power(int n, int x, char arr[])
{
    int temp = 0;
    int last = 0;
    int cnt = 0;
    arr[0] = 1;
    for (int i = 0; i < n; ++i) // 2를 n번 제곱해준다.
    {
        for (int j = 0; j <= last; ++j) // 자릿수만큼 2를 곱해준다.
        {
            temp = arr[j] * x + cnt;
            if (temp >= 10)
            {
                arr[j] = temp % 10;
                cnt = temp / 10;
                if (j == last)
                {
                    arr[++last] = cnt;
                    cnt = 0;
                    break;
                }
            }
            else
            {
                arr[j] = temp;
                cnt = 0;
            }
        }
    }
    arr[0] -= 1;
    for (int i = last; i >= 0; --i)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void move(int start, int dest)
{
    printf("%d %d\n", start, dest);
}

void tower_recursive(int n, int start, int temp, int dest)
{
    if (n == 1)
    {
        move(start, dest);
    }
    tower_recursive(n - 1, start, dest, temp);
    move(start, dest);
    tower_recursive(n - 1, temp, start, dest);
}

int main(void)
{
    char arr[35] = {0};
    int n;
    printf("%d", &n);
    power(n, 2, arr);
    if (n <= 20)
    {
        tower_recursive(n, 1, 2, 3);
    }

    return 0;
}