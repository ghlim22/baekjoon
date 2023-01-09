#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_words
{
	char content[51];
} t_word;

static t_word words[200000];

static int N;

static int my_compare(const void *first, const void *second)
{
	t_word a = *(t_word *)first;
	t_word b = *(t_word *)second;

	int len0 = strlen(a.content);
	int	len1 = strlen(b.content);
	if (len0 == len1)
		return (strcmp(a.content, b.content));
	if (len0 < len1)
		return (-1);
	if (len0 == len1)
		return (0);
	return (1);
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
    	scanf("%50s", words[i].content);
	}
	qsort(words, N, sizeof(t_word), my_compare);
	for (int i = 0; i < N; ++i)
	{
		if (i > 0 && strcmp(words[i-1].content, words[i].content) == 0)
			continue;
		printf("%s\n", words[i].content);
	}
	return (0);
}