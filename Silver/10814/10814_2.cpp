#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct  s_student
{
    int     age;
    string  name;
}       students[100000];

bool compare(const s_student &a, const s_student &b)
{
    return (a.age < b.age);
}

int main(void)
{
    fastio;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> students[i].age >> students[i].name;
    stable_sort(students, students + N, compare);
    for (int i = 0; i < N; ++i)
        cout << students[i].age << " " << students[i].name << "\n";
    return (0);
}