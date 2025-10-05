#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int map[101][101];
bool v[101][101];

void construct(const vector<vector<int>> &rectangle) {
   std::memset(map, -1, sizeof(map));
   for (const auto &vec : rectangle) {
       const int x1 = vec[0] * 2, y1 = vec[1] * 2, x2 = vec[2] * 2, y2 = vec[3] * 2;
       for (int x = x1; x <= x2; ++x) {
           for (int y = y1; y <= y2; ++y) {
               if (x > x1 && x < x2 && y > y1 && y < y2) {
                   map[x][y] = 0;
               } else if (map[x][y] != 0) {
                   map[x][y] = 1;
               }
           }
       }
   }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    construct(rectangle);
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    queue<pair<int, int>> Q;
    Q.push({characterX, characterY});
    v[characterX][characterY] = true;
    
    for (int distance = 0; !Q.empty(); ++distance) {
        int len = Q.size();
        while (len--) {
            const int x = Q.front().first;
            const int y = Q.front().second;
            Q.pop();
            
            if (x == itemX && y == itemY) {
                return distance / 2;
            }
            
            for (int i = 0; i < 4; ++i) {
                const int nx = x + dx[i];
                const int ny = y + dy[i];
                if (!(nx >= 1 && nx <= 100 && ny >= 1 && ny <= 100)) {
                    continue;
                }
                if (v[nx][ny]) {
                    continue;
                }
                if (map[nx][ny] != 1) {
                    continue;
                }
                v[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
    
    return 0;
}