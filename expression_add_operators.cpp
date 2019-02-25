#include <vector>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> expressions;
    if (num.size() == 0) {
      return expressions;
    }

    buildExpressions(num, "", target, 0, 0, 0, expressions);
    return expressions;
  }

  void buildExpressions(const string &num, string expr, int target, int index, 
    int last_add, int value, vector<string> &expressions) {
    if (index == num.size()) {
      if (value == target) {
        expressions.push_back(expr);
      }
      return;
    }

    

    string next_num = "";
    for (int i = index; i < num.size(); i++) {
      next_num += num[i];
      long number = stol(next_num);
      if (number > INT_MAX) {
        return;
      }

      long new_val = 0;
      if (expr.size() == 0) {
        new_val = value + number;
        if (new_val > INT_MAX || new_val < INT_MIN) {
          return;
        }
      buildExpressions(num, expr + next_num, target, i + 1, 
        number, value + number, expressions); 
      }
      else {
        new_val = value + number;
        if (new_val > INT_MAX || new_val < INT_MIN) {
          return;
        }
        buildExpressions(num, expr + '+' + next_num, target, i + 1,
          number, new_val, expressions);

        new_val = value - number;
        if (new_val > INT_MAX || new_val < INT_MIN) {
          return;
        }
        buildExpressions(num, expr + '-' + next_num, target, i + 1,
          -number, new_val, expressions);
        
        new_val = value - last_add + last_add * number;
        if (new_val > INT_MAX || new_val < INT_MIN) {
          return;
        }
        buildExpressions(num, expr + '*' + next_num, target, i + 1,
          last_add * number, new_val, expressions);
      }

      // To prevent leading zeros.
      if (number == 0) {
        return;
      }
    }
  }
};

int main(void) {
  Solution sol;
  for (string s : sol.addOperators("00", 0)) {
    cout << s << " ";
  } 
  cout << endl;
}
