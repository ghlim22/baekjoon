#include <iostream>

int get_distance(int n, int m);
int func_double(int n);
int func_subtract(int n);
int func_left(int n);
int func_right(int n);

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    int start;
    int dest;
    int (*func[4])(int) = {
        func_double,
        func_subtract,
        func_left,
        func_right
    };

    // std::cin >> t;

    // while (t--)
    // {
    // }

    std::cin >> start;
    for (int i = 0; i < 4; ++i)
        std::cout << func[i](start) << "\n";

    return 0;
}

int get_distance(int n, int m)
{
    int sum = 0;

    return sum;
}

int func_double(int n)
{
    return n * 2 % 10000;
}

int func_subtract(int n)
{
    if (n == 0)
        return 9999;
    return n - 1;
}

int func_left(int n)
{
    int lmd = n / 1000; // left-most digit

    return (n % 1000) * 10 + lmd;
}

int func_right(int n)
{
    int rmd = n % 10; // right-most digit

    return n / 10 + rmd * 1000;
}
