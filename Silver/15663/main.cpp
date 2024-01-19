#include <algorithm>
#include <iostream>

int vis[8] = {
    0,
};
int arr[8];
int print[8];
int cnt[10001];
int n;
int m;

void ft_sort(int start, int end) {
  int left = start;
  int right = end;
  int pivot = arr[(start + end) / 2];
  do {
    while (left < end && arr[left] < pivot) {
      ++left;
    }
    while (start < right && arr[right] > pivot) {
      --right;
    }
    if (left <= right) {
      int tmp = arr[right];
      arr[right] = arr[left];
      arr[left] = tmp;
      ++left;
      --right;
    }
  } while (left <= right);
  if (start < right) {
    ft_sort(start, right);
  }
  if (end < left) {
    ft_sort(left, end);
  }
}

void solve(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; ++i) {
            std::cout << print[i];
            if (i < m - 1) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';

        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && !cnt[arr[i]]) {
            vis[i] = 1;
            print[dep] = arr[i];
            solve(dep + 1);
            vis[i] = 0;
        }
    }
}

int main(void) {
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  ft_sort(0, n - 1);
  solve(0);

  return 0;
}