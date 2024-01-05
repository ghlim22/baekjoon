#include <stdio.h>

#define STR_MAX_LEN 102

int main(void)
{
    char str[STR_MAX_LEN];
    char *result;

    while ((result = fgets(str, STR_MAX_LEN, stdin)) != NULL)
    {
        printf("%s", result);
    }
     
    return 0;
}
