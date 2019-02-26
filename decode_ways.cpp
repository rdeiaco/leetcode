#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    if (s.size() == 0) {
      return 0;
    }
    if (s[0] == '0') {
      return 0;
    }
    if (s.size() == 1) {
      return 1;
    }

    int curr_decodings = 0;
    int prev_dec = 1;
    int prev_prev_dec = 1;
    for (int i = 1; i < s.size(); i++) {
      curr_decodings = 0;
      if (s[i] != '0') {
        curr_decodings += prev_dec;
      }
      if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) {
        curr_decodings += prev_prev_dec;
      }
      prev_prev_dec = prev_dec;
      prev_dec = curr_decodings;
    }

    return curr_decodings;
  }

};

int main(void) {
  Solution sol;
  string s = "12";
  cout << sol.numDecodings(s) << endl;
  s = "226";
  cout << sol.numDecodings(s) << endl;
  s = "101010101010101010101010101010101010101010101010";
  cout << sol.numDecodings(s) << endl;
  s = "0";
  cout << sol.numDecodings(s) << endl;
  s = "01";
  cout << sol.numDecodings(s) << endl;
  s = "901";
  cout << sol.numDecodings(s) << endl;

}
