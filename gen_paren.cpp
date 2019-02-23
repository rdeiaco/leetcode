#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    int left_count = 0;
    int right_count = 0;
    vector<string> paren_list;
    string current = "";

    if (n == 0) {
      return paren_list;
    }
    parenHelper(0, 0, n, current, paren_list);
    return paren_list;
  }

  void parenHelper(int left_count, int right_count, int total,
    string current, vector<string> &paren_list) {
    if (left_count == total && right_count == total) {
      paren_list.push_back(current);
      return;
    }

    if (right_count < left_count) {
      parenHelper(left_count, right_count + 1, total,
        current + ')', paren_list);
    }

    if (left_count < total) {
      parenHelper(left_count + 1, right_count, total,
        current + '(', paren_list);
    }

  }
};

int main(void) {
  Solution sol;
  vector<string> result = sol.generateParenthesis(8);
  for (string s : result) {
    cout << s << endl;
  }
}
