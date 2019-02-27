#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }
    constexpr int pow_max = pow(3, floor(log(INT_MAX) / log(3)));
    return n <= pow_max && (pow_max % n == 0);
  }
};

int main(void) {
  Solution sol;
  cout << sol.isPowerOfThree(0) << endl;
  cout << sol.isPowerOfThree(1) << endl;
  cout << sol.isPowerOfThree(3) << endl;
  cout << sol.isPowerOfThree(9) << endl;
  cout << sol.isPowerOfThree(INT_MAX) << endl;
  cout << sol.isPowerOfThree(pow(3, floor(log(INT_MAX) / log(3)))) << endl;
  cout << sol.isPowerOfThree(pow(3, floor(log(INT_MAX) / log(3))) - 1) << endl;
}
