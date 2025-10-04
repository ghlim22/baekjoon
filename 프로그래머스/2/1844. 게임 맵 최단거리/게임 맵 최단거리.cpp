#include <queue>
#include <vector>
using namespace std;

struct point {
    int y;
    int x;
};

bool v[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    queue<point> q;
    v[0][0] = true;
    q.push({0, 0});
    for (int cost = 1; !q.empty(); ++cost) {
        int len = q.size();
        while (len--) {
            int y = q.front().y;
            int x = q.front().x;
            if (y == n - 1 && x == m - 1) {
                return cost;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (!(ny >= 0 && ny < n && nx >= 0 && nx < m)) {
                    continue;
                }
                if (v[ny][nx]) {
                    continue;
                }
                if (maps[ny][nx] == 0) {
                    continue;
                }
                v[ny][nx] = true;
                q.push({ny, nx});
            } 
        } 
    }
    return -1;
}