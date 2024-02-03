#include <cstdio>
#include <stack>

#define MAX_SIZE (1000000)

int LIS[MAX_SIZE];
int map[MAX_SIZE]; /* map[i]: the position of ith input in LIS */
int input[MAX_SIZE];

int lowerbound(int arr[], int size, int key);

int main(void)
{
    int size = 0;
    int pos = 0;
    int len = 0;

    std::scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        std::scanf("%d", &input[i]);
    }

    LIS[len++] = input[0];
    map[0] = 0;
    for (int i = 1; i < size; ++i) {
        if (input[i] > LIS[len - 1]) {
            LIS[len] = input[i];
            map[i] = len;
            ++len;
        } else {
            int pos = lowerbound(LIS, len, input[i]);
            LIS[pos] = input[i];
            map[i] = pos;
        }
    }

    std::printf("%d\n", len);
    std::stack<int> s;
    int cur_idx = len - 1;
    for (int i = size - 1; i >= 0 && cur_idx >= 0; --i) {
        if (cur_idx == map[i]) {
            s.push(input[i]);
            --cur_idx;
        }
    }
    while (!s.empty()) {
        std::printf("%d ", s.top());
        s.pop();
    }
    std::printf("\n");

    return 0;
}

int lowerbound(int arr[], int size, int key)
{
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}