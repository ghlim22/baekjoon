#include <iostream>
#include <queue>

#define MAP_SIZE 100

int map[MAP_SIZE + 1];
int cnt[MAP_SIZE + 1];

void solve();

int main(void)
{
    int n;
    int m;

    std::cin >> n >> m;
    while (n--) 
    {
       int x;
       int y;

       std::cin >> x >> y; 
       map[x] = y;
    }
    while (m--)
    {
        int u;
        int v;

        std::cin >> u >> v;
        map[u] = v;
    }

    solve();
    std::cout << cnt[MAP_SIZE] << "\n";

    return 0;
}

void solve()
{
    int pos;
    int next_pos;
    std::queue<int> q;

    q.push(1);
    while (!q.empty()) 
    {
        pos = q.front();
        q.pop();
        for (int i = 1; i <= 6; ++i) 
        {
            next_pos = pos + i;
            if (next_pos > MAP_SIZE)
            {
                continue;
            }
            if (map[next_pos] > 0) /* Enter into a snake or a ladder */
            {
                next_pos = map[next_pos];
            }
            if (cnt[next_pos] == 0 || cnt[next_pos] > cnt[pos] + 1)
            {
                cnt[next_pos] = cnt[pos] + 1;
                q.push(next_pos);
            } 
        }    
    }
}
