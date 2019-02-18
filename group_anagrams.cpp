#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> anagram_table;

    while (strs.size() != 0) {
      string to_check = strs.back();
      strs.pop_back();

      for (vector<string> &set : anagram_table) {
        if (checkAnagram(set[0], to_check)) {
          set.push_back(to_check);
          continue;
        }
      }
      
      vector<int> indices;
      for (int i = 0; i < strs.size(); i++) {
        if (checkAnagram(to_check, strs[i])) {
          indices.push_back(i);
        }
      }

      vector<string> new_set;
      new_set.push_back(to_check);
      for (auto rit = indices.rbegin(); rit != indices.rend(); rit++) {
        new_set.push_back(strs[*rit]);
        strs.erase(strs.begin() + *rit);
      }
      
      anagram_table.push_back(new_set);
    }

    return anagram_table;

  }

  bool checkAnagram(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) {
      return false;
    }

    int counts1[26] = {0};
    int counts2[26] = {0};

    for (int i = 0; i < s1.size(); i++) {
      counts1[static_cast<int>(s1[i] - 'a')] += 1;
      counts2[static_cast<int>(s2[i] - 'a')] += 1;
    }

    for (int i = 0; i < 26; i++) {
      if (counts1[i] != counts2[i]) {
        return false;
      }
    }

    return true;

  }

};

int main(void) {
  Solution sol;
  vector<string> word_list = {"art", "antelope", "puerto", "eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> anagram_table = sol.groupAnagrams(word_list);

  for (vector<string> set : anagram_table) {
    for (string s : set) {
      cout << s << " ";
    }
    cout << "\n";
  }

}
