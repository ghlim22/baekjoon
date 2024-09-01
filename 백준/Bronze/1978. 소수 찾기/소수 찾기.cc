#include <stdio.h>

int is_prime(int num)
{
	if (num <= 1)
		return 0;
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	int N;
	int res;
	int input;

	res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &input);
		if (is_prime(input))
			++res;
	}
	printf("%d", res);
	return 0;
}