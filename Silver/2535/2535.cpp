// https://www.acmicpc.net/problem/2535
// 2535번

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

// static const int INF = 0x3f3f3f3f;
int printed[100];

struct Student
{
    int Country;
    int Number;
    int Score;
};

bool cmp_student(Student &s1, Student &s2)
{
    return s1.Score > s2.Score;
}

void solve(int count)
{
    Student arr[count];

    for (int i = 0; i < count; ++i)
    {
        cin >> arr[i].Country >> arr[i].Number >> arr[i].Score;
    }

    sort(arr, arr + count, cmp_student);

    int printCount = 0;
    for (int i = 0; i < count; ++i)
    {
        if (printed[arr[i].Country] < 2)
        {
            cout << arr[i].Country << ' ' << arr[i].Number << '\n';
            printed[arr[i].Country]++;
            printCount++;
        }

        if (printCount == 3)
        {
            return;
        }
    }
}

signed main()
{
    int count;
    fastio;

    cin >> count;

    solve(count);

    return 0;
}