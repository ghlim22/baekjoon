#include <assert.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE (10000)

int arr[MAX_SIZE];
char *cmd[5] = {"push", "pop", "size", "empty", "top"};

int main(void)
{
    int cur = -1;
    int size = 0;
    int num;
    char str[30];
    int n;

    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        for (int i = 0; i < 5; ++i) {
            if (strcmp(str, cmd[i]) == 0) {
                switch (i) {
                case 0:
                    scanf("%d", &num);
                    arr[++cur] = num;
                    ++size;
                    break;
                case 1:
                    if (size > 0) {
                        printf("%d\n", arr[cur--]);
                        --size;
                    } else {
                        printf("-1\n");
                    }
                    break;
                case 2:
                    printf("%d\n", size);
                    break;
                case 3:
                    printf("%d\n", size == 0);
                    break;
                case 4:
                    if (size > 0) {
                        printf("%d\n", arr[cur]);
                    } else {
                        printf("-1\n");
                    }
                    break;
                default:
                    assert(0);
                    break;
                }
                break;
            }
        }
    }

    return 0;
}