#include <cstdio>
#include <stack>
#define MAX_SIZE (1000)

int lis[MAX_SIZE];
int input[MAX_SIZE];
int index[MAX_SIZE];

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

    return (right);
}

int main(void)
{
    int lis_len = 1;
    int size = 0;
    int num = 0;

    std::scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        std::scanf("%d", &input[i]); 
    }
    index[0] = 0;
    lis[0] = input[0];
    for (int i = 1; i < size; ++i) {
        if (input[i] > lis[lis_len - 1]) {
            index[i] = lis_len;
            lis[lis_len++] = input[i];
        } else {
            int pos = lowerbound(lis, lis_len, input[i]);
            index[i] = pos;
            lis[pos] = input[i];
        }
    }
    int cur_idx = lis_len - 1;
    std::stack<int> s;
    for (int i = size - 1; i >= 0 && cur_idx >= 0; --i) {
        if (index[i] == cur_idx) {
            s.push(input[i]);
            --cur_idx;
        }
    }
    
    std::printf("%d\n", lis_len);
    while (!s.empty()) {
        std::printf("%d ", s.top());
        s.pop();
    }
    std::printf("\n");

    return (0);
}