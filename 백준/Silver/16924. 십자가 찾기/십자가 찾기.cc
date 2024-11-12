#include <iostream>
#include <queue>
#include <vector>

struct pos {
  int y;
  int x;
};

char MAP[100][100];
bool V[100][100];
int C[100][100];
int N;
int M;
std::vector<pos> CROSS;

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

int build_cross(int r, int c) {
  int size = 0;
  int cnt = 0;
  pos adj[4];
  std::queue<pos> q;
  
  /*
  십자가를 놓을 수 있는 경우에만 새로 채운 *의 개수를 센다.
  */
  for (; true; size++) {
    for (int i = 0; i < 4; ++i) {
      adj[i].y = r + DY[i] * size;
      adj[i].x = c + DX[i] * size;
      if (!(0 <= adj[i].y && adj[i].y < N))
        goto CROSS_RETURN;
      if (!(0 <= adj[i].x && adj[i].x < M))
        goto CROSS_RETURN;
      if (MAP[adj[i].y][adj[i].x] != '*')
        goto CROSS_RETURN;
    }
    for (int i = 0; i < 4; ++i)
      q.push(adj[i]);
  }

CROSS_RETURN:
/*
십자가의 크기는 1 이상이다.
한 칸만 채운 것은 십자가가 아니다.
십자가는 겹쳐서 놓을 수 있기 때문에, *을 중복되지 않게 세어준다.
*/
  if (size > 1) {
    while (!q.empty()) {
      pos cur = q.front();
      q.pop();

      if (V[cur.y][cur.x])
        continue;

      V[cur.y][cur.x] = true;
      cnt++;
    }
    C[r][c] = size - 1;
    CROSS.push_back(pos{.y = r, .x = c});
    return cnt;
  }

  return 0;
}

void print_answer(void) {
  std::cout << CROSS.size() << '\n';
  for (pos p : CROSS) {
    std::cout << p.y + 1 << ' ' << p.x + 1 << ' ' << C[p.y][p.x] << '\n';
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int star = 0;

  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    std::string line;
    std::cin >> line;
    for (int j = 0; j < M; ++j) {
      MAP[i][j] = line[j];
      if (MAP[i][j] == '*')
        star++;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (MAP[i][j] == '*') {
        star -= build_cross(i, j);
      }
    }
  }

  if (star == 0) {
    print_answer();
    return 0;
  }

  std::cout << -1;

  return 0;
}