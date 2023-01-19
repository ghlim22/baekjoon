// https://www.acmicpc.net/problem/17478
// 17478번 

#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>
#define START ("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n")
#define LINE_1 ("\"재귀함수가 뭔가요?\"\n")
#define LINE_2 ("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n")
#define LINE_3 ("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n")
#define LINE_4 ("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n")
#define LINE_5 ("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n")
#define FIN ("라고 답변하였지.\n")

using namespace std;

static int lv;

static void print_underline(int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "____";
	}
}

void solve(int depth) 
{
	if (depth == lv + 1)
		return ;
	print_underline(depth);
	cout << LINE_1;
	if (depth < lv)
	{
		print_underline(depth);
		cout << LINE_2;
		print_underline(depth);
		cout << LINE_3;
		print_underline(depth);
		cout << LINE_4;
	}
	else
	{
		print_underline(depth);
		cout << LINE_5;
	}
	solve(depth + 1);
	print_underline(depth);
	cout << FIN;
}

signed main() {
	fastio;
	cin >> lv;
	cout << START;
	solve(0);
}