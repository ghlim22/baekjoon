#include <iostream>
#include <utility>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

#define LEFT(x) (x * 2)
#define RIGHT(x) (x * 2 + 1)

typedef std::pair<int, int> pii_t;
typedef long long ll;

ll tree[4000001]; // 사탕 맛의 범위에 따른 갯수 누적합, 노드 1부터 시작.
const int ROOT_NODE = 1;
const int TREE_LEFT = 1;
const int TREE_RIGHT = 1000000;

void update(int node, int rangeLeft, int rangeRight, int target, ll diff) {
	if (target > rangeRight || target < rangeLeft) {
		return;
	}
	tree[node] += diff;
	if (rangeLeft == rangeRight) {
		return;
	}
	int mid = (rangeLeft + rangeRight) / 2;
	if (target <= mid) {
		update(LEFT(node), rangeLeft, mid, target, diff);
	} else {
		update(RIGHT(node), mid + 1, rangeRight, target, diff);
	}
}

int get(int node, int rangeLeft, int rangeRight, ll rank) {
	if (rangeLeft == rangeRight) {
		int retval = rangeLeft;
		update(ROOT_NODE, TREE_LEFT, TREE_RIGHT, retval, -1);
		return retval;
	}
	ll leftSum = tree[LEFT(node)];
	int mid = (rangeLeft + rangeRight) / 2;
	if (rank <= leftSum) {
		return get(LEFT(node), rangeLeft, mid, rank);
	} else {
		return get(RIGHT(node), mid + 1, rangeRight, rank - leftSum); // 오른쪽 노드로 가면 왼쪽 노드 부분의 누적합을 빼줘야 순위를 바르게 파악 가능.
	}
}

int main(void) {
  fastio;
  int n;
  std::cin >> n;
  while (n--) {
	ll a, b, c;
	std::cin >> a;
	if (a == 1) {
		std::cin >> b;
		std::cout << get(ROOT_NODE, TREE_LEFT, TREE_RIGHT, b) << '\n';
	} else {
		std::cin >> b >> c;
		update(ROOT_NODE, TREE_LEFT, TREE_RIGHT, b, c);
	}
  }

  return 0;
}