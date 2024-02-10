#include <ctype.h>
#include <stdio.h>
#include <string.h>
char *str = NULL;

int skip_tag(int cur)
{
    while (str[cur] != '\0' && str[cur] != '>') {
        ++cur;
    }
    return cur;
}

int reverse_word(int start)
{
    int end;
    for (end = start; isalnum(str[end]); ++end) {
        ;
    }
    int len = end - start;
    for (int i = 0; i < len / 2; ++i) {
        char tmp = str[start + i];
        str[start + i] = str[end - i - 1];
        str[end - i - 1] = tmp;
    }
    return end - 1;
}

int main(void)
{
    size_t size = 0;
    ssize_t len = getline(&str, &size, stdin);
    for (int i = 0; i < len; ++i) {
        if (str[i] == '<') {
            i = skip_tag(i);
        } else if (isalnum(str[i])) {
            i = reverse_word(i);
        }
    }
    printf("%s\n", str);
    return 0;
}
