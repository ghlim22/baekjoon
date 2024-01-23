#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>

#define MAX_SIZE (100000)

typedef std::pair<int, int> pii;
typedef std::pair<int, pii> sticker;

sticker arr[MAX_SIZE * 2];
int vis[2][MAX_SIZE] = {
    0,
};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int size;
int n;
int t;

static inline void swap(sticker &a, sticker &b)
{
    sticker tmp = a;
    a = b;
    b = tmp;
}

static inline bool is_in_range(int r, int c)
{
    return r >= 0 && r <= 1 && c >= 0 && c < n;
}

/* Non-decreasing order */
static void ft_sort(int start, int end)
{
    int left = start;
    int right = end;
    int pivot = arr[(start + end) / 2].first;

    do {
        while (left <= end && arr[left].first > pivot) {
            ++left;
        }
        while (start <= right && arr[right].first < pivot) {
            --right;
        }
        if (left <= right) {
            swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    } while (left <= right);
    if (start < right) {
        ft_sort(start, right);
    }
    if (left < end) {
        ft_sort(left, end);
    }
}

void solve()
{
    std::memset(vis, 0, sizeof(vis));
    int ans = 0;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        int num = arr[i].first;
        int r = arr[i].second.first;
        int c = arr[i].second.second;
        bool bAvailable = true;
        for (int j = 0; j < 4; ++j) {
            if (is_in_range(r + dy[j], c + dx[j]) &&
                vis[r + dy[j]][c + dx[j]]) {
                bAvailable = false;
                break;
            }
        }
        if (bAvailable) {
            vis[r][c] = 1;
            sum += num;
        }
    }
    ans = sum;

    std::cout << ans << '\n';
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> t;
    while (t--) {
        std::cin >> n;
        size = 2 * n;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                int num;
                std::cin >> num;
                arr[j + i * n].first = num;
                arr[j + i * n].second.first = i;
                arr[j + i * n].second.second = j;
            }
        }
        ft_sort(0, size - 1);
        // for (int i = 0; i < size; ++i) {
        //     std::cout << arr[i].first << ' ' << arr[i].second.first << ' '
        //               << arr[i].second.second << '\n';
        // }
        solve();
    }
    return 0;
}