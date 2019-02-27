#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      digits[i] += 1;
      if (digits[i] == 10) {
        digits[i] = 0;
        if (i == 0) {
          digits.insert(digits.begin(), 1);
        }
      }
      else {
        break;
      }
    }
    return digits;
  }
};

int main(void) {
  Solution sol;
  vector<int> digits = {9, 1, 9, 8};

  digits = sol.plusOne(digits);

  for (int digit : digits) {
    cout << digit << " ";
  }
  cout << endl;

}
