#include <stdio.h>
#include <ctype.h>

int used_cnt[26];

int main(void)
{
	int input;
	int max_idx;

	max_idx = 0;
	while ((input = getchar()) != EOF)
	{
		if (islower(input))
			used_cnt[input - 'a']++;
		else
			used_cnt[input - 'A']++;
	}
	for (int i = 1; i < 26; ++i)
	{
		if (used_cnt[i] > used_cnt[max_idx])
			max_idx = i;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (i != max_idx && used_cnt[max_idx] == used_cnt[i])
		{
			printf("?");
			return 0;
		}
	}
	printf("%c", 'A' + max_idx);
	return 0;
}