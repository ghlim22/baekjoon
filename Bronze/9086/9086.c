#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	char str[1001];

	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		int len = strlen(str);
		printf("%c%c\n", str[0], str[len - 1]);
	}
	return (0);
}
