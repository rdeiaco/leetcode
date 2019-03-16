#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1) {
      return s;
    }

    string zigzag = string(s);

    int zigzag_index = 0;
    for (int i = 0; i < min(numRows, static_cast<int>(s.size())); i++) {
      int down_skip = (numRows - 1 - i) * 2;
      int up_skip = i * 2;
      int j = i;
      bool direction_down = true;

      while (j < s.size()) {
        zigzag[zigzag_index] = s[j];
        zigzag_index++;

        if (up_skip == 0) {
          j += down_skip;
        }
        else if (down_skip == 0) {
          j += up_skip;
        }
        else {
          if (direction_down) {
            j += down_skip;
            direction_down = false;
          }
          else {
            j += up_skip;
            direction_down = true;
          }
        }
      }
    }

    return zigzag;
  }
};

int main(void) {
  Solution sol;
  string s = "paypalishiring";
  cout << sol.convert(s, 12) << endl;


}
