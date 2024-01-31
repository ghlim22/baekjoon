#include <iostream>
#define MAX_SIZE (1000)
int arr[MAX_SIZE];
long sum_arr[MAX_SIZE];
int main(void)
{
    int n;
    long res = 0;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        sum_arr[i] = arr[i];
    }
    res = sum_arr[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && sum_arr[j] + arr[i] > sum_arr[i]) {
                sum_arr[i] = sum_arr[j] + arr[i];
                res = sum_arr[i] > res ? sum_arr[i] : res;
            }
        }
    }
    
    std::cout << res << std::endl;

    return (0);
}