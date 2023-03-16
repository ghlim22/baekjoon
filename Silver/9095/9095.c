#include <stdio.h>

int arr[12];

int main(void)
{
	int	input;
	int	test_cnt;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 11; ++i)
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	scanf("%d", &test_cnt);
	while(test_cnt--)
	{
		scanf("%d", &input);
		printf("%d\n", arr[input]);
	}
	return (0);
}