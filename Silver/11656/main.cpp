#include <iostream>
#include <string>
#include <utility>
#include <vector>

void sort(std::vector<std::string> &v, int low, int high);

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string s;
    std::vector<std::string> v;

    std::cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        v.push_back(s.substr(i));
    }

    sort(v, 0, v.size() - 1);


    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << '\n';
    }

    return 0;
}

void sort(std::vector<std::string> &v, int low, int high)
{
    if (low >= high) {
        return;
    }

    int i = low;
    int j = low;
    std::string &p = v[high];

    for (; j < high; ++j) {
        if (v[j] < p) {
            std::swap(v[i++], v[j]);
        }
    }

    std::swap(v[i], p);

    sort(v, low, i - 1);
    sort(v, i + 1, high);
}
