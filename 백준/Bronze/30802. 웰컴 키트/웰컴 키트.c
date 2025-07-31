#include <stdio.h>

int  main(void) {
	int N, P, T, cnt = 0;
	int shirts[6];

	scanf("%d", &N);
	for (int i = 0; i < 6; ++i) {
		scanf("%d", &shirts[i]);
		cnt += shirts[i];	
	}	

	scanf("%d %d", &T, &P);

	int shirt_count = 0;
	for (int i = 0; i < 6; ++i) {
		shirt_count += shirts[i] / T;
		if (shirts[i] % T != 0) {
			shirt_count += 1;
		}
	}

	printf("%d\n%d %d\n", shirt_count, cnt / P, cnt % P);

	return 0;	
}
