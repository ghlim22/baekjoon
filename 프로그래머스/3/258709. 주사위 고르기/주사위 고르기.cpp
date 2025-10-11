#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int f(int comb, int N, vector<vector<int>> &dice) {
    vector<vector<int>> a_sum(N/2+1, vector<int>(501));
    vector<vector<int>> b_sum(N/2+1, vector<int>(501));
    
    int a_cnt = 1;
    int b_cnt = 1;
    
    for (int i = 0; i < N; ++i) {
        if (comb & (1 << i)) {
            if (a_cnt == 1) {
                for (int j = 0; j < 6; ++j) {
                    int d = dice[i][j];
                    a_sum[a_cnt][d] += 1;
                }
                a_cnt++;
                continue;
            }
            for (int j = 0; j < 6; ++j) {
                int d = dice[i][j];
                for (int k = 1; k <= 400; ++k) {
                    int prev = a_sum[a_cnt - 1][k];
                    if (prev > 0) {
                        a_sum[a_cnt][k + d] += prev;
                    }
                }
            }
            a_cnt++;
        } else {
            if (b_cnt == 1) {
                for (int j = 0; j < 6; ++j) {
                    int d = dice[i][j];
                    b_sum[b_cnt][d] += 1;
                }
                b_cnt++;
                continue;
            }
            for (int j = 0; j < 6; ++j) {
                int d = dice[i][j];
                for (int k = 1; k <= 400; ++k) {
                    int prev = b_sum[b_cnt - 1][k];
                    if (prev > 0) {
                        b_sum[b_cnt][k + d] += prev;
                    }
                }
            }
            b_cnt++;
        }
    }
    
    int a_win = 0;
    for (int k = 1; k <= 500; ++k) {
        int a = a_sum[N/2][k];
        if (a > 0) {
            for (int l = 1; l < k; ++l) {
                int b = b_sum[N/2][l];
                if (b > 0)
                	a_win += a * b;
            }
        }
    }
    
    return a_win;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    int win_count = 0;
    int win_comb = 0;
    
    const int N = dice.size();
    const int lmt = 1 << N;
    for (int i = 0; i < lmt; ++i) {
        bitset<10> bs(i);
        if (bs.count() != N / 2) continue;
        int a_win = f(i, N, dice);
        if (a_win > win_count) {
            win_count = a_win;
            win_comb = i;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (win_comb & (1 << i)) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}