#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    vector<bool> used(n, false);
    string result = "";

    // Make it base zero indexing.
    k--;
    for (int i = 0; i < n; i++) {
      int n_fact = factorial(n - i - 1);
      int index = k / n_fact;
      k %= n_fact;
  
      int count = 0;
      int j = 0;
      // Find first unused index.
      while (used[j]) {
        j++;
      }
      while (j < 9 && count < index) {
        j++;
        if (!used[j]) {
          count++;
        }
      }

      used[j] = true;
      result += to_string(j + 1);
    }

    return result;
  }

  int factorial(int n) {
    int result = 1;
    while (n > 1) {
      result *= n;
      n--;
    }

    return result;
  }
};

int main(void) {
  Solution sol;
  cout << sol.getPermutation(3, 2) << endl;
  cout << sol.getPermutation(3, 3) << endl;
  cout << sol.getPermutation(4, 9) << endl;
  cout << sol.getPermutation(9, sol.factorial(9) - 1) << endl;
}
