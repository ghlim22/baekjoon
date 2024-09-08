#include <iostream>
#include <utility>
#include <vector>

int getGCD(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main(void)
{
    std::cin.tie(NULL)->sync_with_stdio(false);
    int t;
    int n;
    int input;

    std::cin >> t;
    while (t--) {
        std::cin >> n;

        long sum = 0;
        std::vector<int> nums;
        for (int i = 0; i < n; ++i) {
            std::cin >> input;
            nums.push_back(input);
            for (int j = 0; j < i; ++j) {
                sum += getGCD(nums[i], nums[j]);
            }
        }
        std::cout << sum << '\n';
    }

    return 0;
}
