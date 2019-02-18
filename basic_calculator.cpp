#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    stack<int> add_stack;

    bool num_found = false;
    int num_start = 0;
    int num_end = 0;
    int num;
    bool plus_active = true;
    bool minus_active = false;
    bool mul_active = false;
    bool div_active = false;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        continue;
      }

      if (s[i] >= '0' && s[i] <= '9') {
        if (!num_found) {
          num_found = true;
          num_start = i;
          num_end = i + 1;
        }
        else {
          num_end++;
        }
      }

      else {
        num_found = false;
        num = stoi(s.substr(num_start, num_end - num_start));
        if (plus_active) {
          add_stack.push(num);
          plus_active = false;
        }
        if (minus_active) {
          add_stack.push(-num);
          minus_active = false;
        }
        if (mul_active) {
          int temp = add_stack.top();
          add_stack.pop();
          add_stack.push(temp * num);
          mul_active = false;
        }
        if (div_active) {
          int temp = add_stack.top();
          add_stack.pop();
          add_stack.push(temp / num);
          div_active = false;
        }

        if (s[i] == '+') {
          plus_active = true;
        }
        if (s[i] == '-') {
          minus_active = true;
        }
        if (s[i] == '*') {
          mul_active = true;
        }
        if (s[i] == '/') {
          div_active = true;
        }
      }
    }
    
    if (num_found) {
      num = stoi(s.substr(num_start, num_end - num_start));
      if (plus_active) {
        add_stack.push(num);
        plus_active = false;
      }
      if (minus_active) {
        add_stack.push(-num);
        minus_active = false;
      }
      if (mul_active) {
        int temp = add_stack.top();
        add_stack.pop();
        add_stack.push(temp * num);
        mul_active = false;
      }
      if (div_active) {
        int temp = add_stack.top();
        add_stack.pop();
        add_stack.push(temp / num);
        div_active = false;
      }
    }
 
    int sum = 0;
    while (!add_stack.empty()) {
      sum += add_stack.top();
      add_stack.pop();
    }

    return sum;

  }

};

int main(void) {
  Solution sol;
  cout << sol.calculate("3+4*5/3") << "\n"; 
  cout << sol.calculate("") << "\n";
  cout << sol.calculate("2147483647") << "\n";
}


