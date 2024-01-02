#include <iostream>
#include <queue>
#include <utility>

int array[101][101];
int n;
int m;

int find_friend(int src);

int main(void)
{
    std::pair<int, int> ans;

    /* Construct graph structure */
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;

        std::cin >> a >> b;
        array[a][b] = 1;
        array[b][a] = 1;
    }

    /* BFS for each node as a departure point */
    ans.second = __INT32_MAX__;
    for (int i = n; i >= 1; --i)
    {
        int num = find_friend(i);
        if (num <= ans.second)
        {
            ans.first = i;
            ans.second = num;
        }
    }
    std::cout << ans.first << std::endl;

    return 0;
}

int find_friend(int src)
{
    std::queue< std::pair<int, int> > my_queue;
    bool visited[101] = {false, };
    int kevin_number = 0;

    my_queue.push(std::make_pair(src, 0));
    visited[src] = true;
    while (!my_queue.empty())
    {
        int current_node = my_queue.front().first;
        int dist = my_queue.front().second + 1;
        my_queue.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i] || !array[current_node][i])
                continue;
            visited[i] = true;
            my_queue.push(std::make_pair(i, dist));
            kevin_number += dist;
        }
    }
    
    return kevin_number;
}
