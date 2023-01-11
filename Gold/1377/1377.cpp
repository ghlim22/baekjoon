// <https://www.acmicpc.net/problem/1377>
// 1377번 

#include <iostream>
#include <utility>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

/*
static void swap(int *a, int *b)
{
	(*a)^=(*b);
	(*b)^=(*a);
	(*a)^=(*b);
}

static void solve(int *A, int N) 
{
	bool changed = false;
	for (int i=1; i<=N+1; i++) 
	{
    	changed = false;
    	for (int j=1; j<=N-i; j++) 
		{
        	if (A[j] > A[j+1]) 
			{
            	changed = true;
            	swap(A[j], A[j+1]);
        	}
    	}
    	if (changed == false) 
		{
        	cout << i << '\n';
        	break;
    	}
	}
}
*/

signed main() 
{
	fastio;
	int N;
	
	cin >> N;
	pair<int, int> arr[N];
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		arr[i].first = input;
		arr[i].second = i;
	}
	sort(arr, arr + N);
	int ans = 0;
	for (int i = 0; i < N; ++i)
		ans = max(ans, arr[i].second - i);
	cout << (ans + 1) << "\n";
	/*
	for (int i = 0; i < N; ++i)
		cout << arr[i].first << " " << arr[i].second << "\n"; 
	*/
	return 0;
}