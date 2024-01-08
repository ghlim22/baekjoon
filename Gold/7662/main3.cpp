#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define pii std::pair<int, int>
#define MAX_OP 1000000

std::priority_queue< pii > maxHeap;
std::priority_queue< pii, std::vector< pii >, std::greater< pii > > minHeap;
int cnt[MAX_OP];

void clear_properties();

int main(void)
{
  int i;
  int t;
  int k;
  int n;
  int order;
  char c;

  std::cin >> t;
  while (t--) 
  {
    i = 0;
    clear_properties();

    std::cin >> k;

    while (k--) 
    {
      std::cin >> c >> n;

      if (c == 'I')
      {
        cnt[i] = 1;
        minHeap.push(std::make_pair(n, i));
        maxHeap.push(std::make_pair(n, i));
        ++i;
      }
      else if (n == -1 && !minHeap.empty())
      {
        while (!minHeap.empty())
        {
          order = minHeap.top().second;
          if (cnt[order] == 0)
            minHeap.pop();
          else
            break;
        } 
        if (minHeap.empty())
          continue;
        order = minHeap.top().second;
        cnt[order] = 0;
      }
      else if (!maxHeap.empty())
      {
        while (!maxHeap.empty())
        {
          order = maxHeap.top().second;
          if (cnt[order] == 0)
            maxHeap.pop();
          else
           break;
        }
        if (maxHeap.empty())
          continue;
        order = maxHeap.top().second;
        cnt[order] = 0;
      }

    }

    while (!minHeap.empty()) 
    {
      order = minHeap.top().second;
      if (cnt[order] == 0)
        minHeap.pop();
      else
        break;
    }

    while (!maxHeap.empty())
    {
      order = maxHeap.top().second;
      if (cnt[order] == 0)
        maxHeap.pop();
      else
        break;
    }

    if (minHeap.empty() || maxHeap.empty())
      std::cout << "EMPTY\n";
    else       
      std::cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
  }

  return 0;
}

void clear_properties()
{
  memset(cnt, 0, sizeof(int) * MAX_OP);
  while (!maxHeap.empty())
  {
    maxHeap.pop();
  }
  while (!minHeap.empty()) 
  {
    minHeap.pop();
  }
}

