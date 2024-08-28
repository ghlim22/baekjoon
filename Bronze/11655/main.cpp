#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(void)
{
    char *line = NULL;
    size_t capp = 0;

    ssize_t len = getline(&line, &capp, stdin);

    for (int i = 0; i < len; ++i) {
        if (std::islower(line[i])) {
            line[i] = 'a' + (line[i] - 'a' + 13) % 26;
        } else if (std::isupper(line[i])) {
            line[i] = 'A' + (line[i] - 'A' + 13) % 26;
        }
    }

    printf("%s", line);
    free(line);

    return 0;
}
