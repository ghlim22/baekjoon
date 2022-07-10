#include <iostream>
#include <string>
using namespace std;

int arr[26];

int main(void)
{
    char input;
    while ((input = getchar()) != '\n')
    {
        int index = input - 97;
        arr[index]++;
    }

    for (int i = 0; i < 26; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}
