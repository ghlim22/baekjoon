#include <cstdlib>
#include <iostream>

int C;
int P;
int F[100];

int block_one(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 4 > C)
			break;
		if (F[i] == F[i + 1] && F[i + 1] == F[i + 2] && F[i + 2] == F[i + 3])
			cnt++;
	}
	cnt += C;	
	return cnt;
}

int block_two(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 2 > C)
			break;
		if (F[i] == F[i + 1])
			cnt++;
	}	
	return cnt;
}

int block_three(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 3 > C)
			break;
		if (F[i] == F[i + 1] && F[i + 1] == F[i + 2] - 1)
			cnt++;
	}
	for (int i = 0; i < C; ++i) {
		if (i + 2 > C)
			break;
		if (F[i] - 1 == F[i + 1])
			cnt++;
	}	
	return cnt;	
}

int block_four(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 3 > C)
			break;
		if (F[i] - 1 == F[i + 1] && F[i + 1] == F[i + 2])
			cnt++;
	}
	for (int i = 0; i < C; ++i) {
		if (i + 2 > C)
			break;
		if (F[i] == F[i + 1] - 1)
			cnt++;
	}	
	return cnt;	
}


int block_five(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 3 > C)
			break;
		if (F[i] == F[i + 1] && F[i + 1] == F[i + 2])
			cnt++;
		if (F[i] - 1 == F[i + 1] && F[i + 1] == F[i + 2] - 1)
			cnt++;
	}
	for (int i = 0; i < C; ++i) {
		if (i + 2 > C)
			break;
		if (F[i] - 1 == F[i + 1])
			cnt++; 
		if (F[i] == F[i + 1] - 1)
			cnt++; 
	}
	return cnt;	
}

int block_six(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 3 > C)
			break;
		if (F[i] == F[i + 1] && F[i + 1] == F[i + 2])
			cnt++;
		if (F[i] + 1 == F[i + 1] && F[i + 1] == F[i + 2])
			cnt++;
	}
	for (int i = 0; i < C; ++i) {
		if (i + 2 > C)
			break;
		if (F[i] == F[i + 1])
			cnt++; 
		if (F[i] - 2 == F[i + 1])
			cnt++; 
	}
	return cnt;	
}

int block_seven(void) {
	int cnt = 0;
	for (int i = 0; i < C; ++i) {
		if (i + 3 > C)
			break;
		if (F[i] == F[i + 1] && F[i + 1] == F[i + 2])
			cnt++;
		if (F[i] == F[i + 1] && F[i + 1] == F[i + 2] + 1)
			cnt++;
	}
	for (int i = 0; i < C; ++i) {
		if (i + 2 > C)
			break;
		if (F[i] == F[i + 1])
			cnt++; 
		if (F[i] == F[i + 1] - 2)
			cnt++; 
	}
	return cnt;	
}

int main(void) {
	std::cin >> C >> P;
	for (int i = 0; i < C; ++i)
		std::cin >> F[i];

	switch(P) {
		case 1:
			std::cout << block_one();
			break;
		case 2:
			std::cout << block_two();
			break;
		case 3:
			std::cout << block_three();
			break;
		case 4:
			std::cout << block_four();
			break;
		case 5:
			std::cout << block_five();
			break;
		case 6:
			std::cout << block_six();
			break;
		case 7:
			std::cout << block_seven();
			break;
	}

	return 0;
}
