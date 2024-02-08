#include <assert.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE (10000)

int queue[MAX_SIZE];

const char *cmd[6] = {"push", "pop", "size", "empty", "front", "back"};

int main(void)
{
    int size = 0;
    int front = -1;
    int back = -1;
    int n;
    int num;
    char str[20];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        for (int i = 0; i < 6; ++i) {
            if (strcmp(str, cmd[i]) == 0) {
                switch (i) {
                case 0:
                    scanf("%d", &num);
                    if (size == 0) {
                        front = 0;
                        back = -1;
                    }
                    queue[++back] = num;
                    ++size;
                    break;
                case 1:
                    if (size == 0) {
                        printf("-1\n");
                    } else {
                        printf("%d\n", queue[front++]);
                        --size;
                    }
                    break;
                case 2:
                    printf("%d\n", size);
                    break;
                case 3:
                    printf("%d\n", size == 0);
                    break;
                case 4:
                    printf("%d\n", size == 0 ? -1 : queue[front]);
                    break;
                case 5:
                    printf("%d\n", size == 0 ? -1 : queue[back]);
                    break;
                default:
                    assert(0);
                    break;
                }
            }
        }
    }

    return 0;
}