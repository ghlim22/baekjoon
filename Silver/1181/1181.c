#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char words[20000][51];
static int N;

static int my_compare(const void *a, const void *b)
{
    char *str1 = (char *)a;
    char *str2 = (char *)b;

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 == len2)
        return (strcmp(str1, str2));
    if (len1 < len2)
        return (-1);
    if (len1 == len2)
        return (0);
    return (1);
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf(" %s", words[i]);
}