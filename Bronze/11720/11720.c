#include <stdio.h>

int main(void)
{
	int N;
	int res;
	int input;

	res = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%1d", &input);
		res += input;
	}
	printf("%d", res);
	return 0;
}