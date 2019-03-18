#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.size() == 0) {
      return true;
    }

    int j = 0;
    for (int i = 0; i < t.size(); i++) {
      if (s[j] == t[i]) {
        j++;

        if (j == s.size()) {
          return true;
        }

      }
    }

    return false;
  }
};

int main(void) {
  Solution sol;
  cout << sol.isSubsequence("abc", "ahbgdc") << endl;
  cout << sol.isSubsequence("axc", "ahbgdc") << endl;
  cout << sol.isSubsequence("", "ahbgdc") << endl;
  cout << sol.isSubsequence("abc", "") << endl;
}
