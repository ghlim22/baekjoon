#include <stdio.h>
#define FACTOR (10000)
int main(void)
{
	int i;
	int j;
	int n;
	int m;
	int arr[10] = {1, };

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; ++i) {
		/* This loop calculates the numerator of the combination 'n choose k' */
		/* On first element */
		arr[0] *= (n - i + 1);
		for (j = 1; j < 10; ++j) {
			/* This loop muliplies each element of array 'arr' by (n - i + 1), and then performs some carry
			   operations.*/
			/* The carry operation ensures that each element of 'arr' contains only four digits */
			arr[j] *= (n - i + 1);
			arr[j] += arr[j - 1] / FACTOR;
			arr[j - 1] %= FACTOR;
		}
		for (j = 9; j > 0; --j) {
			/* This loop performs the division operations. First, it moves the least digit of an element to the element's prior element. (preventing the loss from integer division).
			This loop is same for the division by the denominator. */
			arr[j - 1] += (arr[j] % i) * FACTOR;
			arr[j] /= i;
		}
		arr[j] /= i;
	}
	for (j = 10; !arr[--j];) {
		;
	}
	for (printf("%d", arr[j]); j--; printf("%04d", arr[j])) {
		;
	}

	return 0;
}
