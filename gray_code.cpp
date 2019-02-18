#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    if (n == 0) {
      vector<int> retval = {0};
      return retval;
    }

    vector<int> retval = grayCode(n-1);
    int length = retval.size();
    int addval = 1 << (n-1);

    for (int i = length-1; i >= 0; i--) {
      retval.push_back(addval + retval[i]);
    }

    return retval;

  }
};

int main(void) {
  Solution sol;
  vector<int> gray = sol.grayCode(0);
  cout << (gray.size() == 0) << "\n\n";

  gray = sol.grayCode(1);
  for (int i : gray) {
    cout << i << "\n";
  }
  cout << "\n";

  gray = sol.grayCode(2);
  for (int i : gray) {
    cout << i << "\n";
  }
  cout << "\n";

}
