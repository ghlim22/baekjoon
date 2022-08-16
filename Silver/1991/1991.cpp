// https://www.acmicpc.net/problem/1991
// 1991번

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) \
    cout << fixed;   \
    cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define MAX (26)
#define IDX(ch) (ch - 'A')

using namespace std;

static const int INF = 0x3f3f3f3f;

int N;
pair<char, char> trees[MAX];

void solve()
{
}

void preorder(int cur)
{
    cout << (char)(cur + 'A');
    if (trees[cur].first != '.')
    {
        preorder(IDX(trees[cur].first));
    }
    if (trees[cur].second != '.')
    {
        preorder(IDX(trees[cur].second));
    }
}

void inorder(int cur)
{
    if (trees[cur].first != '.')
    {
        inorder(IDX(trees[cur].first));
    }
    cout << (char)(cur + 'A');
    if (trees[cur].second != '.')
    {
        inorder(IDX(trees[cur].second));
    }
}

void postorder(int cur)
{
    if (trees[cur].first != '.')
    {
        postorder(IDX(trees[cur].first));
    }
    if (trees[cur].second != '.')
    {
        postorder(IDX(trees[cur].second));
    }
    cout << (char)(cur + 'A');
}

signed main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char ch;
        cin >> ch;
        cin >> trees[IDX(ch)].first >> trees[IDX(ch)].second;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}