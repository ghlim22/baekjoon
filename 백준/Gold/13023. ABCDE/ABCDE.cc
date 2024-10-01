#include <cstdio>
#include <iostream>
#include <vector>
#define MAX (2000)
int n;
int m;
std::vector< std::vector<int> > graph(MAX);
std::vector<bool> visited(MAX, false);

void dfs(int cur, int dep) {
	if (dep == 4) {
		printf("1\n");
		exit(0);
	}

	visited[cur] = true;
	for (int f : graph[cur]) {
		if (visited[f])
			continue;
		dfs(f, dep + 1);
	}	
	visited[cur] = false;
}

int main(void) {
  /* INPUT */
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
	graph[a].push_back(b);
	graph[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) {
	dfs(i, 0);	
  }

  printf("0\n");

  return 0;
}