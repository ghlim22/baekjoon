// https://www.acmicpc.net/problem/10825
// 10825번

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

struct Student
{
    string Name;
    int Korean;
    int English;
    int Math;
};

bool compare_student(const Student &s1, const Student &s2)
{
    if (s1.Korean != s2.Korean)
    {
        return s1.Korean > s2.Korean;
    }

    if (s1.English != s2.English)
    {
        return s1.English < s2.English;
    }

    if (s1.Math != s2.Math)
    {
        return s1.Math > s2.Math;
    }

    return s1.Name < s2.Name;
}

void solve(int count)
{
    Student arr[count];

    for (int i = 0; i < count; ++i)
    {
        cin >> arr[i].Name >> arr[i].Korean >> arr[i].English >> arr[i].Math;
    }

    sort(arr, arr + count, compare_student);

    for (int i = 0; i < count; ++i)
    {
        cout << arr[i].Name << '\n';
    }
}

signed main()
{
    fastio;
    int N;
    cin >> N;
    solve(N);

    return 0;
}