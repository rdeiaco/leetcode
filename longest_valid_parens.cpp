#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.size() <= 1) {
      return 0;
    }

    int max_size = 0;
    int open_count = 0;
    int closed_count = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        open_count++;
      }
      else if (s[j] == ')') {
        closed_count++;
      }
      if (closed_count == open_count) {
        max_size = max(max_size, open_count + closed_count);
      }
      if (closed_count > open_count) {
        open_count = 0;
        closed_count = 0;
      }
    }

    open_count = 0;
    closed_count = 0;
    for (int j = s.size() - 1; j >= 0; j--) {
      if (s[j] == '(') {
        open_count++;
      }
      else if (s[j] == ')') {
        closed_count++;
      }
      if (open_count == closed_count) {
        max_size = max(max_size, open_count + closed_count);
      }
      else if (open_count > closed_count) {
        open_count = 0;
        closed_count = 0;
      }
    }

    return max_size;
  }
};

int main(void) {
  Solution sol;
  cout << sol.longestValidParentheses(")()())") << endl;
}

