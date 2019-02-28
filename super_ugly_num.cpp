#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <climits>
#include <cstdint>

using namespace std;

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<int, vector<int>, greater<int>> heap;
    int count = 0;
    heap.push(1);

    int ugly_number = 0;

    while (count < n) {
      int64_t temp = static_cast<int64_t>(heap.top());
      heap.pop();
      if (temp == ugly_number) {
        continue;
      }

      for (int prime : primes) {
        int64_t prod = temp * static_cast<int64_t>(prime);
        if (prod <= INT_MAX) {
          heap.push(prod);
        }
      }
      ugly_number = temp;
      count++;
    }

    return ugly_number;

  }
};

int main(void) {
  Solution sol;
  vector<int> primes = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
  cout << sol.nthSuperUglyNumber(100000, primes) << endl;
}
