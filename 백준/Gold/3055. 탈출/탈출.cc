/*
문제
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기
위해 근처의 티떱숲에 홍수를 일으키려고 한다. 이 숲에는 고슴도치가 한 마리 살고
있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고
한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이
차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의
위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위,
아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과
인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는
돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도
비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해
필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인
칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기
때문이다.

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와
'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약,
안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.
*/

#include <iostream>
#include <queue>
#include <utility>

#define MAX (50)

typedef std::pair<int, int> pii_t;

const int DY[4] = {0, -1, 1, 0};
const int DX[4] = {-1, 0, 0, 1};

const char *FAILURE_MSG = "KAKTUS";

int R;
int C;
char MAP[MAX][MAX];
bool HEDGEHOG_VISITED[MAX][MAX];
bool WATER_VISITED[MAX][MAX];

std::queue<pii_t> HEDGEHOG;
std::queue<pii_t> WATER;

pii_t HEDGEHOG_ORIGIN;
pii_t WATER_ORIGIN;

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    std::string line;
    std::cin >> line;
    for (int j = 0; j < C; ++j) {
      MAP[i][j] = line[j];
      if (MAP[i][j] == 'S') {
        HEDGEHOG_VISITED[i][j] = true;
        HEDGEHOG.push(std::make_pair(i, j));
        MAP[i][j] = '.';
      } else if (MAP[i][j] == '*') {
        WATER.push(std::make_pair(i, j));
      }
    }
  }
}

void solve(void) {
  for (int time = 0; !HEDGEHOG.empty(); ++time) {
    int hsize = HEDGEHOG.size();
    int wsize = WATER.size();

    while (wsize--) {
      pii_t cur = WATER.front();
      WATER.pop();
      for (int i = 0; i < 4; ++i) {
        pii_t n = std::make_pair(cur.first + DY[i], cur.second + DX[i]);
        if (!(n.first >= 0 && n.first < R && n.second >= 0 && n.second < C))
          continue;
        if (MAP[n.first][n.second] != '.')
          continue;
        MAP[n.first][n.second] = '*';
        WATER.push(n);
      }
    }

    while (hsize--) {
      pii_t cur = HEDGEHOG.front();
      HEDGEHOG.pop();

      if (MAP[cur.first][cur.second] == 'D') {
        std::cout << time;
        return;
      }
      for (int i = 0; i < 4; ++i) {
        pii_t n = std::make_pair(cur.first + DY[i], cur.second + DX[i]);
        if (!(n.first >= 0 && n.first < R && n.second >= 0 && n.second < C))
          continue;
        if (HEDGEHOG_VISITED[n.first][n.second])
          continue;
        if (MAP[n.first][n.second] == '*' || MAP[n.first][n.second] == 'X')
          continue;
        HEDGEHOG_VISITED[n.first][n.second] = true;
        HEDGEHOG.push(n);
      }
    }
  }

  std::cout << FAILURE_MSG;
}

int main(void) {
  input();
  solve();
  return 0;
}
