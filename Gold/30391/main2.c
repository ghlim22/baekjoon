#include <stdio.h>

int main(void)
{
	int n;
	int k;
	int cur = 1;
	int cnt = 0;
	int global_cnt = 0;

	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n && global_cnt < n - 1; ++i) {
		if (cnt == k) {
			++cur;
			cnt = 1;
		}
		printf("%d %d\n", cur, i);
		++cnt;
		++global_cnt;
	}

	return 0;
}