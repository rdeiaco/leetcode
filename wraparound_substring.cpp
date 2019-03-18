#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  int findSubstringInWraproundString(string p) {
    int count = 0;
    int length_table[26] = {0};

    int i = 0;
    int j = 0;
    while (i < p.size()) {
      if (j == p.size()) {
        length_table[p[i] - 'a'] = max(length_table[p[i] - 'a'], j - i);
        i++;
      }
      else if (i == j || static_cast<int>(p[j] - p[j - 1]) == 1 || (p[j] == 'a' && p[j - 1] == 'z')) {
        j++;
      }
      else {
        length_table[p[i] - 'a'] = max(length_table[p[i] - 'a'], j - i);
        i++;
      }
    }

    for (int subcount : length_table) {
      count += subcount;
    }

    return count;

  }
};

int main(void) {
  Solution sol;
  cout << sol.findSubstringInWraproundString("a") << endl; 
  cout << sol.findSubstringInWraproundString("cac") << endl; 
  cout << sol.findSubstringInWraproundString("zab") << endl; 
  cout << sol.findSubstringInWraproundString("zabzabcdg") << endl; 
}
