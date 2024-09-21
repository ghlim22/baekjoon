#include <stdlib.h>
#include <stdio.h>

#define SIZE (9)

void sort(int *a, int low, int high);
void print(int *a, int x, int y);

int main(void)
{
    const int size = SIZE;
    int input[SIZE];
    int total = 0;

    for (int i = 0; i < size; ++i) {
        scanf("%d", &input[i]);
        total += input[i];
    }

    sort(input, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (total - input[i] - input[j] == 100) {
                print(input, i, j);
                goto EXIT;
            }
        }
    }

    EXIT:
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int *a, int low, int high)
{
    if (low >= high) {
        return;
    }

    int i = low;
    int j = low;
    int *pivot = &a[high];

    for (; j < high; ++j) {
        if (a[j] < *pivot) {
            swap(&a[i++], &a[j]);
        }
    }

    swap(&a[i], pivot);

    sort(a, low, i - 1);
    sort(a, i + 1, high);
}

void print(int *a, int x, int y) 
{
    for (int i = 0; i < SIZE; ++i) {
        if (i == x || i == y)
            continue;
        printf("%d\n", a[i]);
    }
}
