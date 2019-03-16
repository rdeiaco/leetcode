#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findLUSlength(vector<string> &strs) {
    int max_length = -1;

    for (int i = 0; i < strs.size(); i++) {
      bool uncommon = true;
      for (int j = 0; j < strs.size(); j++) {
        if (i == j) {
          continue;
        }

        // Check if string i is a subseq of string j.
        int k = 0;
        int l = 0;
        while (k < strs[i].size() && l < strs[j].size()) { 
          if (strs[i][k] == strs[j][l]) {
            k++;
          }

          l++;
        }

        if (k == strs[i].size()) {
          uncommon = false;
          break;
        }
      }

      if (uncommon) {

        max_length = max(max_length, static_cast<int>(strs[i].size()));
      }

    }

    return max_length;

  }
};

int main(void) {
  Solution sol;
  vector<string> strs = {"aabbcc", "aabbcc", "cb", "abc"}; 
  cout << sol.findLUSlength(strs) << endl;

}
