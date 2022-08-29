// https://www.acmicpc.net/problem/1991_2
// 1991_2번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX_SIZE (26)

using namespace std;

static const int INF = 0x3f3f3f3f;

pii tree[MAX_SIZE];
int N;

void preorder(char ch)
{
    if (ch == '.')
    {
        return;
    }

    cout << ch;
    preorder(tree[ch - 'A'].first);
    preorder(tree[ch - 'A'].second);
}

void inorder(char ch)
{
    if (ch == '.')
    {
        return;
    }

    inorder(tree[ch - 'A'].first);
    cout << ch;
    inorder(tree[ch - 'A'].second);
}

void postorder(char ch)
{
    if (ch == '.')
    {
        return;
    }

    postorder(tree[ch - 'A'].first);
    postorder(tree[ch - 'A'].second);
    cout << ch;
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char node, left, right;
        cin >> node >> left >> right;
        tree[node - 'A'].first = left;
        tree[node - 'A'].second = right;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

    return 0;
}