#include <stdio.h>
int main(void)
{
    int n;
    int digits = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i *= 10){
        digits += (n + 1 - i);
    }
    printf("%d\n", digits);
    
    return 0;
}