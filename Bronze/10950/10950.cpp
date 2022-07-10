#include <iostream>
using namespace std;

int main(void)
{
    int count, a, b;

    scanf("%d", &count);

    for (int i = 0; i < count; ++i)
    {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}