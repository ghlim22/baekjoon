#include <functional>
#include <iostream>
#include <set>
#include <queue>

int main(void)
{
    int t;
    int k;
    int num;
    int size;
    char c;
    std::multiset<int> ms;

    std::scanf("%d", &t);
    while (t--)
    {
        size = 0;

        std::scanf("%d", &k);
        while (k--)
        {
            std::scanf(" %c", &c);
            std::scanf("%d", &num);
            if (c == 'I')
                ms.insert(num);
            else if (!ms.empty())
            {
                if (num == -1)
                    ms.erase(ms.begin());
                else
                    ms.erase(--ms.end());
            }
        }

        if (ms.empty())
            std::printf("EMPTY\n");
        else
            std::printf("%d %d\n", *(--ms.end()), *ms.begin());

        ms.clear();
    }

    return 0;
}
