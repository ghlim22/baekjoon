#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>

int get_distance(int n, int m);
int func_double(int n);
int func_subtract(int n);
int func_left(int n);
int func_right(int n);

void search();

int (*func[4])(int) = {
    func_double,
    func_subtract,
    func_left,
    func_right
};

int start;
int dest;
int vis[10000];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;

    std::cin >> t;

    while (t--)
    {
        std::memset(vis, 0, sizeof(vis));
        std::cin >> start >> dest;
        search();
    }

    return 0;
}

int get_distance(int n, int m)
{
    int sum = 0;

    for (int i = 1; i <= 1000; i *= 10)
    {
        sum += std::abs((n / i) % 10 - (m / i) % 10);
    }
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

void search()
{
    std::queue< std::pair<int, std::string> > q;

    q.push(std::make_pair(start, ""));
    while (!q.empty())
    {
        int next;
        char ch;
        int n = q.front().first;
        std::string trace = q.front().second;
        
        if (n == dest)
            break;

        for (int i = 0; i < 4; ++i)
        {
            next = func[i](n);
            if (!vis[next])
            {
                switch (i)
                {
                case 0:
                    ch = 'D';
                    break;
                case 1:
                    ch = 'S';
                    break;
                case 2:
                    ch = 'L';
                    break;
                case 3:
                    ch = 'R';
                    break;
                default:
                    break;
                }

                vis[next] = 1;
                q.push(std::make_pair(next, trace + ch));
            } 
        }
        q.pop();
    }

    std::cout << q.front().second << "\n";
}
