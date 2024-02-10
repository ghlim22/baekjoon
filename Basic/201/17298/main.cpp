#include <cstdio>
#include <stack>
#define MAX_SIZE (1000000)
int input[MAX_SIZE];
int nge[MAX_SIZE];
int main(void)
{
    std::stack<int> stk;
    int n;

    std::scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::scanf("%d", &input[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        nge[i] = -1;
        while (!stk.empty() && stk.top() <= input[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            nge[i] = stk.top();
        }
        stk.push(input[i]);
    }
    for (int i = 0; i < n; ++i) {
        std::printf("%d ", nge[i]);
    }
    std::printf("\n");
    return 0;
}