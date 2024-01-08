#include <iostream>
#include <set>

int main(void)
{
    int t;
    int k;
    int n;
    char c;
    std::multiset<int> ms;

    std::cin >> t;

    while (t--)
    {
        std::cin >> k;
        while (k--)
        {
            std::cin >> c >> n;
            if (c == 'I')
            {
                ms.insert(n);
            }
            else /* c == 'D' */
            {
                if (ms.empty())
                {
                    continue;
                }
                
                if (n == -1)
                {
                    ms.erase(ms.begin());
                }
                else
                {
                    ms.erase(--ms.end());
                }
            }
        }

        if (ms.empty())
        {
            std::cout << "EMPTY\n";
        }
        else
        {
            std::cout << *(--ms.end()) << " " << *ms.begin() << "\n";
        }
        
        ms.clear();
    }

    return 0;
}
