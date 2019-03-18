#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict_set;
    vector<bool> invalid(s.size() + 1, false);
    for (string word : wordDict) {
      dict_set.insert(word);
    }

    return wordBreakHelper(s, 0, dict_set, invalid);
    
  }

  vector<string> wordBreakHelper(const string &s, int index,
    const unordered_set<string> &dict_set, vector<bool> &invalid) {
    vector<string> results;

    if (index == s.size()) {
      results.push_back("");
      return results;
    }

    for (int i = index + 1; i <= s.size(); i++) {
      string prefix = s.substr(index, i - index);
      string suffix = s.substr(i, s.size() - i);
      if (dict_set.find(prefix) != dict_set.end() && !invalid[i]) {
        vector<string> sub_results = wordBreakHelper(s, i, dict_set, invalid);
        if (sub_results.size() == 0) {
          invalid[i] = true;
        }

        for (string res : sub_results) {
          if (res.size() == 0) {
            results.push_back(s.substr(index, i - index));
          }
          else {
            results.push_back(s.substr(index, i - index) + " " + res);
          }
        }
      }
    }

    return results;

  }
};

int main(void) {
  Solution sol;
  string s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  vector<string> result = sol.wordBreak(s, wordDict);
  for (string res : result) {
    cout << res << endl;
  }
  cout << endl;

  s = "pineapplepenapple";
  wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
  result = sol.wordBreak(s, wordDict);
  for (string res : result) {
    cout << res << endl;
  }
  cout << endl;

  s = "catsandog";
  wordDict = {"cats", "dog", "sand", "and", "cat"};
  result = sol.wordBreak(s, wordDict);
  for (string res : result) {
    cout << res << endl;
  }
  cout << endl;
  
  s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  result = sol.wordBreak(s, wordDict);
  for (string res : result) {
    cout << res << endl;
  }
  cout << endl;

  s = "aaaaaaa";
  wordDict = {"aaaa", "aaa"};
  result = sol.wordBreak(s, wordDict);
  for (string res : result) {
    cout << res << endl;
  }
  cout << endl;



}
