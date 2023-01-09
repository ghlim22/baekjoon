#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_student
{
    char name[11];
    int kor;
    int eng;
    int math;
};

static int compare_int_ascending(int a, int b)
{
    if (a > b)
        return (1);
    if (a == b)
        return (0);
    return (-1);
}

static int compare_students(const void *a, const void *b)
{
    struct s_student first = *(struct s_student *)a;
    struct s_student second = *(struct s_student *)b;

    if (first.kor == second.kor && first.eng == second.eng && first.math == second.math)
        return (strcmp(first.name, second.name));
    if (first.kor == second.kor && first.eng == second.eng)
        return (-compare_int_ascending(first.math, second.math));
    if (first.kor == second.kor)
        return (compare_int_ascending(first.eng, second.eng));
    return (-compare_int_ascending(first.kor, second.kor));
}

int main(void)
{
    int N;

    scanf("%d", &N);
    struct s_student arr[N];
    for (int i = 0; i < N; ++i)
    {
        scanf(" %s %d %d %d", arr[i].name, &arr[i].kor, &arr[i].eng, &arr[i].math);
    }
    qsort(arr, N, sizeof(struct s_student), compare_students);
    for (int i = 0; i < N; ++i)
        printf("%s\n", arr[i].name);
    return (0);
}