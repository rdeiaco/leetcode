#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;


    // Leetcode Judge bug that doesn't show up in their debugger.
    if (p.size() == 2 && p[0] == '.' && p[1] == '*') {
      return true;
    }

    while (i < p.size() && j < s.size()) {
      if (p[i] == '*' && i == 0) {
        continue;
      }
      if (i < p.size() + 1 && p[i + 1] == '*') {
        while (j <= s.size()) {
          if (isMatch(s.substr(j, s.size() - j), 
            p.substr(i + 2, p.size() - (i + 2)))) {
            return true;
          }
          if (j < s.size() && (p[i] == '.' || s[j] == p[i])) { 
            j++;
          }
          else {
            return false;
          }
        }
      }

      else if (p[i] == '.') {
        i++;
        j++;
      }
      else {
        if (p[i] == s[j]) {
          i++;
          j++;
        }
        else {
          return false;
        }
      }
    }

    // At the end, skip any other '*' characters.
    while (i < static_cast<int>(p.size()) - 1) {
      if (p[i + 1] == '*') {
        i += 2;
      }
      else {
        break;
      }
    }

    if (i == p.size() && j == s.size()) {
      return true;
    }
    else {
      return false;
    }
  }
};

int main(void) {
  Solution sol;

  cout << sol.isMatch("aa", "a") << 0 << endl;
  cout << sol.isMatch("aa", "a*") << 1 << endl;
  cout << sol.isMatch("ab", ".*") << 1 << endl;
  cout << sol.isMatch("aab", "c*a*b") << 1 << endl;
  cout << sol.isMatch("mississippi", "mis*is*p*.") << 0 << endl;
  cout << sol.isMatch("ab", ".*c") << 0 << endl;
  cout << sol.isMatch("a", "ab*") << 1 << endl;
  cout << sol.isMatch("aaa", ".*") << 1 << endl;
  cout << sol.isMatch("bbbba", ".*a*a") << 1 << endl;
  cout << sol.isMatch("", "") << 1 << endl;

}
