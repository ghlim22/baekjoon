#include <stdio.h>

int main(void)
{
	char	arr[101];
	int	len;

	len = 0;
	scanf("%s", arr);
	while (arr[len])
		len++;
	printf("%d", len);
	return (0);
}
