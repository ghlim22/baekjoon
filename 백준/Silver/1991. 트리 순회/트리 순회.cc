#include <iostream>

int N;
int tree[26][2];

void input() {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    char a, b, c;
    std::cin >> a >> b >> c;
    tree[a - 'A'][0] = ((b == '.') ? -1 : b - 'A');
    tree[a - 'A'][1] = ((c == '.') ? -1 : c - 'A');
  }
}

void preorder(int idx) {
  if (idx == -1)
    return;
  std::cout << (char)(idx + 'A');
  preorder(tree[idx][0]);
  preorder(tree[idx][1]);
}

void inorder(int idx) {
  if (idx == -1)
    return;
  inorder(tree[idx][0]);
  std::cout << (char)(idx + 'A');
  inorder(tree[idx][1]);
}

void postorder(int idx) {
  if (idx == -1)
    return;
  postorder(tree[idx][0]);
  postorder(tree[idx][1]);
  std::cout << (char)(idx + 'A');
}

void solve() {
  preorder(0);
  std::cout << '\n';
  inorder(0);
  std::cout << '\n';
  postorder(0);
  std::cout << '\n';
}

int main(void) {
  input();
  solve();
  return 0;
}