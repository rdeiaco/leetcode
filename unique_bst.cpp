#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    if (n == 0) {
      return 0;
    }

    vector<int> lut(n + 1, 0);  
    lut[0] = 1;
    lut[1] = 1;

    // i is the number of nodes.
    for (int i = 2; i <= n; i++) {
      // j is the current root value of the BST's.
      for (int j = 1; j <= i; j++) {
        lut[i] += (lut[j - 1] * lut[i - j]);
      }
    }

    return lut[n];
  }
};

int main(void) {
  Solution sol;
  cout << sol.numTrees(0) << endl;
  cout << sol.numTrees(1) << endl;
  cout << sol.numTrees(3) << endl;
  cout << sol.numTrees(4) << endl;
}
