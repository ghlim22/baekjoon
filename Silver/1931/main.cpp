//https://www.acmicpc.net/problem/1931
//회의실 배정

#include <iostream>
#include <algorithm>
using namespace std;

struct meeting
{
    int start_time, end_time;
}meetings[100001]; // 회의 시간을 저장할 구조체 배열

/*
 두 미팅의 끝나는 시간을 비교해 오름차 순으로 정렬.
 끝나는 시간이 같다면 시작 시간을 비교해 오름차 순으로 정렬.
 */
bool MeetingCompare(const meeting& x, const meeting& y)
{
    if (x.end_time != y.end_time)
    {
        return x.end_time < y.end_time;
    }
    else
    {
        return x.start_time < y.start_time;
    }
}


int main(int argc, const char * argv[])
{
    int count; // 회의의 수
    
    cin >> count;
    
    for (int i = 0; i < count; ++i)
    {
        cin >> meetings[i].start_time >> meetings[i].end_time;
    }
    
    sort(meetings, meetings + count, MeetingCompare);
    
    int marker = 0; // 회의 종료시간 저장.
    int ans = 0; // 배정된 회의 수.
    
    for (int i = 0; i < count; ++i)
    {
        if (meetings[i].start_time >= marker)
        {
            marker = meetings[i].end_time;
            ans++;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
