#include <stdio.h>
#define DIV_NUM (10000)
int arr[10] = {
    1,
};

int main(void)
{
    int i;
    int j;
    int n;
    int k;

	scanf("%d %d", &n, &k);

	for (i = 1; i <= k; ++i) {
		/* This loop calculates the numerator of the 'n choose k' */
		arr[0] *= (n - k + i); /* (n - k + 1) (n - k + 2 ) ... (n) */
		for (j = 1; j < 10; ++j) {
			/* This loop performs the mulication on the numerator and 
			some carry operations, which ensures that each element of
			'arr' contains only four digits. */
			arr[j] *= (n - k + i);
			arr[j] += (arr[j - 1] / DIV_NUM);
			arr[j - 1] %= DIV_NUM;
		}
		for (j = 9; j > 0; --j) {
			/* This loop performs the division 'numerator' / k! */
			/* Save the truncated part of integer division */
			arr[j - 1] += ((arr[j] % i) * DIV_NUM);
			arr[j] /= i;
		}
		arr[j] /= i;
	}

	/* Find the first non-zero element from 'arr' */
	for (i = 9; !arr[i]; --i) {
		;
	}

	for (printf("%d", arr[i]); i--; printf("%04d", arr[i])) {
		;
	}
	printf("\n");

    return (0);
}