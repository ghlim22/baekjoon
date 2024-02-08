#include <assert.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE (10000)

int deque[MAX_SIZE * 2 + 2];

const char *cmd[8] = {"push_front", "push_back", "pop_front", "pop_back",
                      "size",       "empty",     "front",     "back"};

int main(void)
{
    int size = 0;
    int front = MAX_SIZE + 1;
    int back = MAX_SIZE + 1;
    int n;
    int num;
    char str[20];

    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        for (int i = 0; i < 8; ++i) {
            if (strcmp(str, cmd[i]) == 0) {
                switch (i) {
                case 0:
                    scanf("%d", &num);
                    if (front == back) {
                        ++back;
                    }
                    deque[front--] = num;
                    ++size;
                    break;
                case 1:
                    scanf("%d", &num);
                    if (front == back) {
                        --front;
                    }
                    deque[back++] = num;
                    ++size;
                    break;
                case 2:
                    if (size == 0) {
                        printf("-1\n");
                    } else {
                        printf("%d\n", deque[++front]);
                        --size;
                    }
                    break;
                case 3:
                    if (size == 0) {
                        printf("-1\n");
                    } else {
                        printf("%d\n", deque[--back]);
                        --size;
                    }
                    break;
                case 4:
                    printf("%d\n", size);
                    break;
                case 5:
                    printf("%d\n", size == 0);
                    break;
                case 6:
                    printf("%d\n", size == 0 ? -1 : deque[front + 1]);
                    break;
                case 7:
                    printf("%d\n", size == 0 ? -1 : deque[back - 1]);
                    break;
                default:
                    assert(0);
                    break;
                }
                continue;
            }
        }
    }

    return 0;
}