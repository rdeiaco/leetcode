#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
      int start_index = 0;
      int end_index = 0;
      bool positive = true;

      for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
          continue;
        }

        if (str[i] == '+') {
          start_index = i + 1;
          break;
        }
        else if (str[i] == '-') {
          start_index = i + 1;
          positive = false;
          break;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
          start_index = i;
          break;
        }
        else {
          return 0;
        }
      }

      for (int i = start_index; i < str.size(); i++) {
        if (str[i] == '0') {
          start_index++;
        }
        else {
          break;
        }
      }

      end_index = start_index;
      for (int i = start_index; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
          end_index++;
        }
        else {
          break;
        }
      }

      long int base = 1;
      long int result = 0;

      if (end_index == start_index) {
        return 0;
      }
      if (end_index - start_index > 10) {
        result = positive ? INT_MAX : INT_MIN;
        return result;
      }

      for (int i = end_index-1; i >= start_index; i--) {
        result += static_cast<int>(str[i] - '0') * base;
        if (result > INT_MAX) {
          result = positive ? INT_MAX : INT_MIN;
          return static_cast<int>(result);
        }

        base *= 10;
      }

      if (!positive) {
        result = -result;
      }

      return result;

    }
};

int main(void) {
  Solution sol;
  cout << sol.myAtoi("  -9999999999") << "\n";
}
