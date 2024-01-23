#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#define MAX_SIZE (10000)

typedef std::pair<int, int> pii;

int n = 0;
int result = 0;
std::vector<pii> tree[MAX_SIZE + 1];

void input()
{
    int a;
    int b;
    int weight;

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> a >> b >> weight;
        tree[a].push_back(std::make_pair(b, weight));
    }
}

int solve(int s)
{
    int max = 0;
    int second = 0;
    for (pii i : tree[s]) {
        int len = solve(i.first) + i.second;
        if (len > max) {
            second = max;
            max = len;
        } else if (len > second) {
            second = len;
        }
    }
    result = std::max(result, max + second);
    return max;
}

int main(void)
{
    input();
    solve(1);
    std::cout << result << std::endl;
    return 0;
}