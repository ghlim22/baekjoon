#include <stdio.h>
#include <string.h>

void solve(int n, char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%c", str[i]);
	}
	printf("\n");
}

int main(void)
{
	int T;

	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int N;
		char str[21];
		scanf("%d", &N);
		scanf("%s", str);
		solve(N, str);
	}

	return 0;
}