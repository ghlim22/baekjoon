//
//  main.cpp
//  15649_N과M(1)
//
//  Created by 임규현 on 2022/04/14.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[9];
vector<int> subset;

void PrintSubsetRecursive();

int main(int argc, const char * argv[])
{
    cin >> N >> M;
    
    PrintSubsetRecursive();
    
    return 0;
}

void PrintSubsetRecursive()
{
    if (subset.size() == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << subset[i] << ' ';
        }
        cout << '\n';
        
        return;
    }
    
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            subset.push_back(i);
            PrintSubsetRecursive();
            subset.pop_back();
            visited[i] = 0;
        }
    }
}
