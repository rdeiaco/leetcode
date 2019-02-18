#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, bool> dict;
    for (string str : wordDict) {
      dict[str] = true;
    }

    return wordSearch(s, dict);
  }

  bool wordSearch(string s, unordered_map<string, bool> dict) {
    bool memo[s.size()][s.size()] = {0};
    for (int j = 0; j < s.size(); j++) {
      for (int i = j; i >= 0; i--) {
        bool valid = false;
        if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
          valid = true;
        }

        for (int k = i; k < j; k++) {
          valid |= (memo[i][k] && memo[k+1][j]);
        }

        memo[i][j] = valid;

      }
    }

    return memo[0][s.size()-1];

  }

};

int main(void) {
  Solution sol;

  string s = "leetcode";
  vector<string> dict = {"leet", "code"};
  cout << sol.wordBreak(s, dict) << "\n";

  s = "applepenapple";
  dict = {"apple", "pen"};
  cout << sol.wordBreak(s, dict) << "\n"; 

  s = "catsandog";
  dict = {"cats", "dog", "sand", "and", "cat"};
  cout << sol.wordBreak(s, dict) << "\n"; 

}



