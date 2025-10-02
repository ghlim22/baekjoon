#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct mydata {
    int y;
    int x;
};

const int M = 1000000007;
int dy[2] = {1, 0};
int dx[2] = {0, 1};
int len[101][101];
int map[101][101];

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i < puddles.size(); ++i) {
        len[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    std::queue<mydata> Q; 
    Q.push({1, 1});
    map[1][1] = 1;
    while (!Q.empty()) {
        mydata curr = Q.front();
        map[curr.y][curr.x] %= M;
        if (curr.y == n && curr.x == m)
            break;
        Q.pop();
        for (int i = 0; i < 2; ++i) {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];
            if (!(ny >= 1 && ny <= n && nx >= 1 && nx <= m))
                continue;
            if (len[ny][nx] != 0 && len[ny][nx] < len[curr.y][curr.x] + 1)
                continue;
            if (len[ny][nx] == 0) {
            	Q.push({ny, nx});
            }
            len[ny][nx] = len[curr.y][curr.x] + 1; 
            map[ny][nx] += map[curr.y][curr.x];
        }
    } 
    
    return map[n][m] % M;
}