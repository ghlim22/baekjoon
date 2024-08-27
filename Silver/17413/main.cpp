#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int reverse(char *line, const int start)
{
    int end = start;
    while (std::isalnum(line[end])) {
        ++end;
    }
    int len = end - start;
    for (int i = 0; i < len / 2; ++i) {
        char c = line[start + i];
        line[start + i] = line[end - 1 - i];
        line[end - 1 - i] = c;
    }
    return end - 1;
}

int main(void)
{
    char *line = NULL;
    size_t size = 0;

    getline(&line, &size, stdin);
    size_t len = strlen(line);
    
    for (int i = 0; i < len; ++i) {
        if (line[i] == '<') {
            while (line[i] != '>') {
                ++i;
            }
        } else if (isalnum(line[i])) {
            i = reverse(line, i);
        }
    }

    printf("%s", line);
    free(line);

    return 0;
}
