#include <iostream>

#define MAX (100)

int arr[MAX][MAX] = {
    0,
};

int main(void)
{
    int n;
    int x;
    int y;
    int ans = 0;

    std::cin >> n;
    while (n--) {
        std::cin >> x >> y;
        for (int r = y; r < y + 10; ++r) {
            for (int c = x; c < x + 10; ++c) {
                if (!arr[r][c]) {
                arr[r][c] = 1;
                ++ans;
                }
            }
        }
    }
    std::cout << ans;

    return 0;
}
