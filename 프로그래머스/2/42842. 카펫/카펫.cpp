#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int width = 1; width <= 2000000; ++width) {
        int height = yellow / width;
        if (width < height) continue;
        if (width * 2 + height * 2 + 4 == brown) {
            return {width + 2, height + 2};
        }
        
    }
    
    return answer;
}