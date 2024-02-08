#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    size_t len = 0;
    char *str = NULL;
    int tc = 0;

    scanf("%d", &tc);
    getc(stdin);
    while (tc--) {
        getline(&str, &len, stdin);
        int i = 0;
        while (i < len) {
            if (!isalpha(str[i])) {
                i++;
                continue;
            }
            int j = i;
            while (isalpha(str[j])) {
                ++j;
            }
            for (int k = 0; k < (j - i) / 2; ++k) {
                char tmp = str[i + k];
                str[i + k] = str[j - k - 1];
                str[j - k - 1] = tmp;
            }
            i = j + 1;
        }
        printf("%s", str);
        free(str);
        str = NULL;
        len = 0;
    }

    return 0;
}