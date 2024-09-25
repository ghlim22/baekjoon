#include <stdio.h>

int n;

void print(int depth) {
	if (depth > n) {
		return;
	}
	for (int i = 0; i < n - depth; ++i) {
		printf(" ");
	}
	for (int i = 0; i < depth * 2 - 1; ++i) {
		printf("*");
	}
	printf("\n");

	print(depth + 1);
	if (depth == n) {
		return;
	}

	for (int i = 0; i < n - depth; ++i) {
		printf(" ");
	}
	for (int i = 0; i < depth * 2 - 1; ++i) {
		printf("*");
	}
	printf("\n");	
}


int main(void)
{
	scanf("%d", &n);
	print(1);
	return 0;
}