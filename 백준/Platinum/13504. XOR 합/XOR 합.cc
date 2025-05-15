#include <iostream>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
    std::ios::sync_with_stdio(false);                                          \
    std::cin.tie(0);                                                           \
    std::cout.tie(0);                                                          \
  } while (0)

struct Node
{
	Node()
	{
		children[0] = -1;
		children[1] = -1;
	}
	int children[2];
};

typedef std::vector<Node> Trie;

unsigned int A[100001];

int init(Trie &trie)
{
	Node x;
	trie.push_back(x);
	return trie.size() - 1;
}

void add(Trie &trie, int node, int num, int index) {
	if (index == -1) {
		return;
	}

	int b = (num >> index) & 1;
	if (trie[node].children[b] == -1) {
		int next = init(trie);
		trie[node].children[b] = next;
	}
	int child = trie[node].children[b];
	add(trie, child, num, index - 1);
}

int doXOR(Trie &trie, int node, int num, int index)
{
	if (index == -1) {
		return 0;
	}

	int b = (num >> index) & 1;
	int cur = 0;
	int child = trie[node].children[b];
	if (trie[node].children[b ^ 1] != -1) {
		cur = 1;
		child = trie[node].children[b ^ 1];
	}
	return doXOR(trie, child, num, index - 1) | (cur << index);
}

int main()
{
	fastio;

	int T, N, elem;

	std::cin >> T;
	while (T--) {
		std::cin >> N;

		Trie trie;
		int root = init(trie);

		add(trie, root, 0, 31);
		for (int i = 1; i <= N; ++i) {
			std::cin >> elem;
			A[i] = A[i - 1] ^ elem; /* A[1..i]의 xor합을 누적한다. */
			add(trie, root, A[i], 31);  /* Trie에 A[1..i]의 xor합을 추가한다. */
		}

		int maxVal = 0;
		for (int i = 0; i <= N; ++i) {
			/* xor 누적합이 들어있는 trie를 사용하여, A[1..i]와 xor연산을 했을 때 
			   최댓값이 나오는  A[1..x]를 상수 시간에 구할 수 있다. 
			   이 xor결과가 i를 왼쪽 또는 오른쪽의 끝으로 하는 연속 부분 수열의 xor최댓값이다. */
			int xorResult = doXOR(trie, root, A[i], 31);
			if (maxVal < xorResult) {
				maxVal = xorResult;
			}
		}

		std::cout << maxVal << '\n';
	}

	return 0;
}