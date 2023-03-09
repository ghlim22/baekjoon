#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char	str[1000001];
	int	cnt;
	int	len;
	int	in_word;

	cnt = 0;
	in_word = 0;
	scanf("%[^\n]", str);
	len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (isspace(str[i]))
			in_word = 0;
		else if (!in_word)
		{
			cnt++;
			in_word = 1;
		}
	}
	printf("%d", cnt);
	
	return (0);
}
