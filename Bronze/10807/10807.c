#include <stdio.h>

int main(void)
{
	int n;
	int arr[202] = {0, };
	int v;

	scanf("%d", &n);
	while (n--)
	{
		int input;
		scanf("%d", &input);
		arr[input + 100]++;
	}	
	scanf("%d", &v);
	printf("%d", arr[v + 100]);
	return (0);
}