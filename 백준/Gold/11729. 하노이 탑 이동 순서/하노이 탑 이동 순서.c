#include <stdio.h>

void f(int n, int from, int through, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}

	f(n - 1, from, to, through); // move n - 1 disks [from -> to -> through]
	printf("%d %d\n", from, to); // move #n disk [from -> to]
	f(n - 1, through, from ,to); // move n - 1 disks [through, from, to]
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	f(n, 1, 2, 3);

	return 0;
}