#include <cstddef>
#include <iostream>
#include <vector>

void QuickSort(int start, int end, std::vector<std::string> &vec)
{

    const int mid = (start + end) / 2;
    int left = start;
    int right = end;
    std::string piv = vec[mid];

    while (left <= right) {
        while (left <= right && vec[left] < piv) {
            ++left;
        }
        while (left <= right && vec[right] > piv) {
            --right;
        }
        std::string tmp = vec[left];
        vec[left] = vec[right];
        vec[right] = tmp;
        ++left;
        --right;
    }
}

int main(void)
{
    std::string line;
    std::vector<std::string> words;

    std::cin >> line;
    size_t len = line.size();
    for (int i = 1; i <= len; ++i) {
        words.push_back(line.substr(0, i));
    }
}