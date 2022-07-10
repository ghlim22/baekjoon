#include <iostream>
#include <vector>
using namespace std;

void PrintRecursive(int idx, int next);

int N, M;
int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

int main(void)
{
    cin >> N >> M;
    PrintRecursive(1, 2);

    return 0;
}

void PrintRecursive(int start, int next)
{
    if (start == N || next == N + 1)
    {
        return;
    }

    if (start < next)
    {
        cout << start << ' ' << next << '\n';
        PrintRecursive(start, next + 1);
        PrintRecursive(start + 1, next + 1);
    }
}
