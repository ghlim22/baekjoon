#include <cmath>
#include <iostream>
#include <queue>

struct cmp
{
    bool operator()(int a, int b)
    {
        int abs_a = std::abs(a);
        int abs_b = std::abs(b);

        if (abs_a == abs_b)
            return a > b;
        return abs_a > abs_b;
    }
};

int main(void)
{
    std::priority_queue<int, std::vector<int>, cmp> pque;
    int n;
    int x;

    std::scanf("%d", &n);
    while (n--)
    {
        std::scanf("%d", &x);
        switch (x)
        {
        case 0:
            if (pque.empty())
            {
                std::printf("0\n");
            }
            else
            {
                std::printf("%d\n", pque.top());
                pque.pop();
            }
            break;
        default:
            pque.push(x);
            break;
        }
    }
    
    return 0;
}
