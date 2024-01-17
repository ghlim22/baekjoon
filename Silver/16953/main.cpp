#include <iostream>
#include <set>
#include <queue>
#include <utility>

typedef std::pair<int, int> pii_t;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a;
    int b;
    std::set<long> s;
    std::queue<pii_t> q;

    std::cin >> a >> b;

    s.insert(a);
    q.push(std::make_pair(a, 0));
    while (!q.empty()) {
        int cur_num = q.front().first;
        int cur_dep = q.front().second;
        long arr[2] = {cur_num * 2, cur_num * 10 + 1};
        for (int i = 0; i < 2; ++i) {
            if (s.count(arr[i]) == 0) {
                if (arr[i] < b) {
                    s.insert(arr[i]);
                    q.push(std::make_pair(arr[i], cur_dep + 1));
                } else if (arr[i] == b) {
                    std::cout << cur_dep + 1 + 1 << '\n';
                    goto end_program;
                }
            }
        }
        q.pop();
    }

    if (q.empty()) {
        std::cout << -1 << '\n';
    }

    end_program:

    return 0;
}
