#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

typedef std::pair<int, int> pii_t;

const int d4y[4] = {0, -1, 1, 0};
const int d4x[4] = {-1, 0, 0, 1};
const int d8y[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int d8x[8] = {-1, 1, -1, 0, 1, -1, 0, 1};

int main(void) {
  fastio;
  
  long n, l, k;
  std::cin >> n >> l >> k;
  
  std::vector<int> jumpsSum(l + 1);
  for (int i = 0; i < k; ++i) {
	int p; 
	std::cin >> p;
	jumpsSum[p] = 1;
  }
  for (int i = 1, sum = 0; i <= l; ++i) {
	if (jumpsSum[i] == 1) {
		sum++;
	}
	jumpsSum[i] = sum;
  }

  for (long frameNo = 1, speed = 1, curSceneNo = 1;;frameNo++) {
	long nextSpeedAdd = 0;
	long s = speed;
	if (s >= l - curSceneNo + 1) {
		nextSpeedAdd += jumpsSum[l] - jumpsSum[curSceneNo - 1];
		s -= (l - curSceneNo + 1);
		curSceneNo = 1;
		n--;
	}
	if (s >= l) {
		n -= (s / l);
		nextSpeedAdd += jumpsSum[l] * (s / l);
		s = s % l;
	}

	nextSpeedAdd += jumpsSum[curSceneNo + s - 1] - jumpsSum[curSceneNo - 1];
	curSceneNo += s;
	speed += nextSpeedAdd;

	if (n <= 0) {
		std::cout << frameNo << '\n';
		break;
	}
  }

  return 0;
}