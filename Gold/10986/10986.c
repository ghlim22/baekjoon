#include <stdio.h>

static int cnt_of_sum[1000];

int main(void)
{
	int N, M;
	long long ans, tmp, sum;

	ans = 0;
	sum = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &tmp);
		sum += tmp;
		cnt_of_sum[sum % M]++;
	}
	ans += cnt_of_sum[0];
	for (int i = 0; i < M; ++i)
	{
		if (cnt_of_sum[i])
			ans += (long long)cnt_of_sum[i] * (cnt_of_sum[i] - 1) / 2;
	}
	printf("%lld", ans);
	return (0);
}