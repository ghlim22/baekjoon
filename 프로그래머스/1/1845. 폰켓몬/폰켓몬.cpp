#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for (int num : nums) {
        s.insert(num);
    }
    return min(nums.size() / 2, s.size());
}