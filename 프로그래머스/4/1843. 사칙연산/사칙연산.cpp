#include <algorithm>
#include <climits>
#include <vector>
#include <string>
using namespace std;

bool VMAX[201][201];
bool VMIN[201][201];
int MAXIMUM[201][201];
int MINIMUM[202][201];

int find_max(vector<string> &arr, int i, int j);

int find_min(vector<string> &arr, int i, int j) {
    if (VMIN[i][j])
        return MINIMUM[i][j];
    if (i == j) {
        VMIN[i][j] = true; 
        return MINIMUM[i][j] = std::stoi(arr[i]);
    }
    
    VMIN[i][j] = true;
    int min_val = INT_MAX;
    for (int k = i + 1; k < j; k += 2) {
        if (arr[k][0] == '+') {
            int curr = find_min(arr, i, k - 1) + find_min(arr, k + 1, j);
            min_val = std::min(min_val, curr);
        } else {
            int curr = find_min(arr, i, k - 1) - find_max(arr, k + 1, j);
            min_val = std::min(min_val, curr);
        }
    }
    
    return MINIMUM[i][j] = min_val;
}

int find_max(vector<string> &arr, int i, int j) {
    if (VMAX[i][j])
        return MAXIMUM[i][j];
    if (i == j) {
        VMAX[i][j] = true; 
        return MAXIMUM[i][j] = std::stoi(arr[i]);
    }
    
    VMAX[i][j] = true;
    int max_val = INT_MIN;
    for (int k = i + 1; k < j; k += 2) {
        if (arr[k][0] == '+') {
           	int curr = find_max(arr, i, k - 1) + find_max(arr, k + 1, j); 
            max_val = std::max(max_val, curr);
        } else {
            int curr = find_max(arr, i, k - 1) - find_min(arr, k + 1, j);
            max_val = std::max(max_val, curr);
        }
    }
    
    return MAXIMUM[i][j] = max_val;
}

int solution(vector<string> arr)
{
    return find_max(arr, 0, arr.size() - 1);
}