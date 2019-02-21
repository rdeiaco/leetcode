#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1.0;
    }

    bool neg_flag = false;
    if (n < 0) {
      neg_flag = true;
    }

    double acc = 1;
    while (n > 1 || n < -1) {
      if (n & 1) {
        acc *= x;
        if (neg_flag) {
          n += 1;
        }
        else {
          n -= 1;
        }
      }
      else {
        x *= x;
        n >>= 1;
      }
    }

    if (neg_flag) {
      return 1.0 / (acc * x);
    }
    else {
      return acc * x;
    }

  }
};

int main(void) {
  Solution sol;
  cout << sol.myPow(3.0, 3) << endl;
  cout << sol.myPow(2.5, 4) << endl;
  cout << sol.myPow(2.0, -2) << endl;
  cout << sol.myPow(-2.5, 3) << endl;
  cout << sol.myPow(-2.5, -3) << endl;
  cout << sol.myPow(-2.5, 4) << endl;
  cout << sol.myPow(-2.5, -4) << endl;

  cout << sol.myPow(2.5, 0) << endl;
  cout << sol.myPow(2.5, 1) << endl;
  cout << sol.myPow(2.5, -1) << endl;
  cout << sol.myPow(1.0, INT_MIN) << endl;
  cout << sol.myPow(1.0, INT_MAX) << endl;
  cout << sol.myPow(0.00001, INT_MAX) << endl;
}
