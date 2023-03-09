#include <stdio.h>

int main(void)
{
	int arr[42] = {0, };
	int cnt = 0;

	for (int i = 0; i < 10; ++i)
	{
		int num;

		scanf("%d", &num);
		if (arr[num % 42] == 0){
			arr[num % 42]++;
			cnt++;
		}
	}
	printf("%d", cnt);
	return (0);
}