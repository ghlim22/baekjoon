#include <string>
#include <vector>

using namespace std;

int f(vector<int> &numbers, const int target, const int index, const int sum) {
    if (index == numbers.size()) {
        return (target == sum) ? 1 : 0;
    }
    return f(numbers, target, index + 1, sum + numbers[index]) + f(numbers, target, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    return f(numbers, target, 0, 0);
}