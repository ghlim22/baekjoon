#include <cstring>
#include <iostream>
#define MAX_SIZE (1000)
#define SWAP(x, y)                                                             \
    do {                                                                       \
        int tmp = x;                                                           \
        x = y;                                                                 \
        y = tmp;                                                               \
    } while (0)

char strs[MAX_SIZE][MAX_SIZE + 1];
int arr[MAX_SIZE];

void sort(int start, int end)
{
    int left = start;
    int right = end;
    int pivot = (start + end) / 2;

    do {
        while (left <= end &&
               std::strcmp(strs[arr[left]], strs[arr[pivot]]) < 0) {
            ++left;
        }
        while (right >= start &&
               std::strcmp(strs[arr[right]], strs[arr[pivot]]) > 0) {
            --right;
        }
        if (left <= right) {
            SWAP(arr[left], arr[right]);
            ++left;
            --right;
        }
    } while (left <= right);

    if (start < right) {
        sort(start, right);
    }
    if (left < end) {
        sort(left, end);
    }
}

int main(void)
{
    int size = 0;
    char str[MAX_SIZE + 1];
    std::cin >> str;
    size = std::strlen(str);
    std::strcpy(strs[0], str);

    for (int i = 1; i < size; ++i) {
        arr[i] = i;
        std::strcpy(strs[i], str + i);
    }
    sort(0, size - 1);
    for (int i = 0; i < size; ++i) {
        std::cout << strs[arr[i]] << '\n';
    }

    return 0;
}