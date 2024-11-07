#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int spf[10000];
bool isPrime[10000];
std::vector<int> primes;

bool VISITED[10000];

void findPrimes(void) {
  for (int i = 2; i < 10000; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      isPrime[i] = true;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (p * i >= 10000)
        break;
      spf[p * i] = p;
      if (i % p == 0)
        break;
    }
  }
}

void integerToArray(int n, int *arr) {
  arr[3] = n % 10;
  arr[2] = n % 100 / 10;
  arr[1] = n % 1000 / 100;
  arr[0] = n / 1000;
}

int arrayToIntger(int *arr) {
  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    ret *= 10;
    ret += arr[i];
  }
  return ret;
}

int bfs(int a, int b) {
  memset(VISITED, 0, sizeof(VISITED));
  VISITED[a] = true;
  std::queue<int> q;
  q.push(a);
  for (int cost = 0; !q.empty(); ++cost) {
    int qsize = q.size();
    while (qsize--) {
      int cur = q.front();
      q.pop();

      if (cur == b) {
        return cost;
      }

      int arr[4];
      for (int idx = 0; idx < 4; ++idx) {
        for (int digit = 0; digit < 10; ++digit) {
          integerToArray(cur, arr);
          arr[idx] = digit;

          int next = arrayToIntger(arr);
          if (next < 1000)
            continue;
          if (VISITED[next])
            continue;
          if (!isPrime[next])
            continue;

          VISITED[next] = true;
          q.push(next);
        }
      }
    }
  }
  return -1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  findPrimes();

  int T;
  std::cin >> T;
  while (T--) {
    int a, b;
    std::cin >> a >> b;

    int ret = bfs(a, b);
    if (ret == -1)
      std::cout << "Impossible\n";
    else
      std::cout << ret << '\n';
  }

  return 0;
}