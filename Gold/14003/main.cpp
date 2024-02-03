#include <cstdio>
#include <cstring>
#include <stack>

#define MAX_SIZE (1000000)

int inputs[MAX_SIZE];
int prev[MAX_SIZE];
int lis[MAX_SIZE];

int lowerbound(int len, int key)
{
    int left = 0;
    int right = len;

    while (left < right) {
        int mid = (left + right) / 2;
        if (inputs[lis[mid]] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return (right);
}

int main(void)
{
    int size = 0;
    int lis_len = 0;

    std::scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        std::scanf("%d", &inputs[i]);
    }

	std::memset(prev, -1, sizeof(prev));
    lis[lis_len++] = 0; // insert the first index to the LIS array.
    for (int i = 1; i < size; ++i) {
        if (inputs[i] > inputs[lis[lis_len - 1]]) {
            prev[i] = lis[lis_len - 1];
            lis[lis_len++] = i;
        } else {
            int pos = lowerbound(lis_len, inputs[i]);
            if (pos > 0) {
                prev[i] = lis[pos - 1];
            }
			lis[pos] = i;
        }
    }

	std::printf("%d\n", lis_len);
	std::stack<int> s;
	s.push(inputs[lis[lis_len - 1]]);
	for (int i = lis[lis_len - 1]; prev[i] != -1; i = prev[i]) {
		s.push(inputs[prev[i]]);
	}
	while (!s.empty()) {
		std::printf("%d ", s.top());
		s.pop();
	}
	std::printf("\n");
	
    return (0);
}