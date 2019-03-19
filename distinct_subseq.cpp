#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    vector<int> lut((s.size() + 1) * (t.size() + 1), -1);
    return numDistinctHelper(s, t, 0, 0, lut);
  }

  int numDistinctHelper(string &s, string &t, int s_index, int t_index, vector<int> &lut) {
    if (t_index == t.size()) {
      return 1;
    }

    int count = 0;
    for (int i = s_index; i < s.size(); i++) {
      if (s[i] == t[t_index]) {
        int lut_val = lut[(i + 1) * (t.size() + 1) + t_index + 1];
        if (lut_val != -1) {
          count += lut_val; 
        }
        else {
          count += numDistinctHelper(s, t, i + 1, t_index + 1, lut);
        }
      }
    }

    lut[s_index * (t.size() + 1) + t_index] = count;
    return count;
  }
};

int main(void) {
  Solution sol;

  cout << sol.numDistinct("rabbbit", "rabbit") << endl;
  cout << sol.numDistinct("babgbag", "bag") << endl;
  cout << sol.numDistinct("babgbag", "bag") << endl;
  cout << sol.numDistinct("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc", "bcddceeeebecbc") << endl;
  cout << sol.numDistinct("abag", "bag") << endl;
}
