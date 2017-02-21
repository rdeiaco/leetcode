#include <vector>
#include <cmath>
#include <iostream>

class Solution {
  public:
  int numSquares(int n) {
    std::vector<int> memo(n+1, 0);
    return numSquares_sub(n, memo);
  }

  int numSquares_sub(int n, std::vector<int> &memo) {
    // Base case, no more operations required.
    if (n == 0) {
      return 0;
    }
    // Check memo for solution.
    if (memo[n] != 0) {
      return memo[n];
    }

    // Else, calculate minimum sub-solution.
    int i, min, temp;
    int sqrt_n = floor(sqrt(n));

    min = n;
    for (i = 0; i < sqrt_n; i++) {
      int n_next = n - (i+1)*(i+1);
      temp = 1 + numSquares_sub(n_next, memo);
      if (temp < min) {
        min = temp;
      }
    }

    if (memo[n] == 0) {
      memo[n] = min;
    }

    return min;
  }
};

int main(void) {
  Solution sol;
  std::cout << sol.numSquares(13) << "\n";
  return 0;
}
