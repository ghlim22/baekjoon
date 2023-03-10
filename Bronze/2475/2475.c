#include <stdio.h>

int main(void)
{
	int	input;
	int	sum;
	int	cert;

	sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &input);
		sum += input * input;
	}
	cert = sum % 10;
	printf("%d", cert);
	return (0);
}
