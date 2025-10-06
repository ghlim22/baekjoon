#include <string>
#include <vector>

#define MAXIMUM 10000000

using namespace std;

vector<int> primes;
vector<int> spf(MAXIMUM);
vector<bool> v(7);

void get_primes() {
    for (int i = 2; i < MAXIMUM; ++i) {
        if (spf[i] == 0) {
        	primes.push_back(i);
        	spf[i] = i;
        }
        for (int j : primes) {
            int x = i * j;
            if (x >= MAXIMUM) break;
            spf[x] = j;
            if (i % j == 0) break;
        }
    }
}

int f(string &numbers, int sum) {
   int ret = 0;
   if (sum > 0 && spf[sum] == sum) {
       ret += 1;
       spf[sum] = 0; // visit
   }
   for (int i = 0; i < numbers.size(); ++i) {
       if (!v[i]) {
           v[i] = true;
           ret += f(numbers, 10 * sum + numbers[i] - '0');
           v[i] = false;
       }
   }
   return ret;
}

int solution(string numbers) {
    get_primes();
    return f(numbers, 0);
}