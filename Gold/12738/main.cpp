#include <cstdio>
#define MAX_SIZE (1000000)

int lis[MAX_SIZE];

int lowerbound(int arr[], int len, int key)
{
    int left = 0;
    int right = len;

    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return (right);
}

int main(void)
{
    int size;
    int len = 0;
    int num;

    std::scanf("%d", &size);
    scanf("%d", &lis[len++]);
    for (int i = 1; i < size; ++i) {
        std::scanf("%d", &num);
        if (num > lis[len - 1]) {
            lis[len++] = num;
        } else {
            int pos = lowerbound(lis, len, num);
            lis[pos] = num;
        }
    }

    std::printf("%d\n", len);

    return (0);
}