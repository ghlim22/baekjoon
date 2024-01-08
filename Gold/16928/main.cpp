#include <iostream>
#include <queue>

#define BOARD_SIZE 100

static int board[BOARD_SIZE + 1] = {
    0,
};
static int count[BOARD_SIZE + 1] = {
    0,
};

void solve();

int main(void)
{
    int n;
    int m;
    int x;
    int y;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    /* Input */
    std::cin >> n >> m;
    while (n--)
    {
        std::cin >> x >> y;
        board[x] = y;
    }
    while (m--)
    {
        std::cin >> x >> y;
        board[x] = y;
    }

    solve();
    std::cout << count[BOARD_SIZE] << "\n";

    return 0;
}

void solve()
{
    std::queue<int> q;
    int next_pos;
    int x;

    /* Initialize the queue. */
    q.push(1);

    /* Run BFS. */
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (x >= BOARD_SIZE)
        {
            continue;
        }
        for (int i = 1; i <= 6; ++i)
        {
            next_pos = x + i;
            if (next_pos > BOARD_SIZE)
            {
                continue;
            }
            if (board[x + i] > 0)
            {
               next_pos = board[x + i];
            }
            /* Update count[next_pos] and push next_post into the queue
             * when current path is the new optimal path.
             * We can prevent a cycle caused by a snake using this
             * update policy.
             */
            if (count[next_pos] == 0 || count[next_pos] > count[x] + 1)
            {
                count[next_pos] = count[x] + 1;
                q.push(next_pos);
            }
        }
    }
}
