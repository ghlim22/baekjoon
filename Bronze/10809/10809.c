#include <stdio.h>
#include <memory.h>

int main(void)
{
	char	str[101];
	int		arr[26];
	int i;

	memset(arr, -1, sizeof(int) * 26);
	scanf("%s", str);
	i = 0;
	while (str[i])
	{
		if (arr[str[i] - 'a'] == -1)
			arr[str[i] - 'a'] = i;
		++i;
	}
	i = 0;
	while (i < 26)
	{
		printf("%d ", arr[i]);
		++i;
	}
	return (0);
}