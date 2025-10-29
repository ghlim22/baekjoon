#include <map>
#include <iostream>
#include <utility>
#include <vector>

#define fastio                                                                 \
  do {                                                                         \
	std::ios::sync_with_stdio(false);                                          \
	std::cin.tie(0);                                                           \
	std::cout.tie(0);                                                          \
  } while (0)

struct node {
	std::map<std::string, node> m;
};

void insert(int depth, std::vector<std::string> &path, node &tree) {
	if (depth == path.size()) {
		return;
	}

	if (tree.m.find(path[depth]) == tree.m.end()) {
		tree.m.insert({path[depth], node()});
	}

	auto &subtree = tree.m.find(path[depth])->second;
	insert(depth + 1, path, subtree);
}

void print(int depth, node &tree) {
	for (auto &s : tree.m) {
		for (int i = 0; i < depth; ++i) {
			std::cout << "--";
		}
		std::cout << s.first << '\n';
		print(depth + 1, s.second);
	}
}

int main(void) {
  fastio;

  int N;
  std::cin >> N;

  node tree;
  for (int i = 0; i < N; ++i) {
	int K;
	std::cin >> K;
	std::vector<std::string> path;
	for (int j = 0; j < K; ++j) {
		std::string s;
		std::cin >> s;
		path.push_back(s);
	}

	insert(0, path, tree);
	path.clear();
  }

  print(0, tree);

  return 0;
}