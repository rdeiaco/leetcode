#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (t.size() == 0) {
      return "";
    }

    vector<int> char_table(255, 0);
    vector<int> t_count(255, 0);
    unordered_set<char> t_lookup;
    int window_char_count = 0;
    
    // Insert each char, and increment the char count for t.
    for (char c : t) {
      t_lookup.insert(c);
      t_count[c]++;
    }

    int i = 0;
    int j = 0;
   
    // Find the index of the first character in s that is
    // also in t. 
    while (i < s.size()) {
      if (t_lookup.find(s[i]) != t_lookup.end()) {
        char_table[s[i]]++;
        window_char_count++;
        break;
      }
      i++;
    }
    if (i == s.size()) {
      return "";
    }
    if (window_char_count == t.size()) {
      return s.substr(i, window_char_count);
    }

    // Find the first valid window that exists in s.
    j = i + 1;
    while (j < s.size() && window_char_count < t.size()) {
      if (t_lookup.find(s[j]) != t_lookup.end()) {
        if (char_table[s[j]] < t_count[s[j]]) {
          window_char_count++;
        }
        char_table[s[j]]++;
      }
      j++;
    }
    if (j == s.size() && window_char_count < t.size()) {
      return "";
    }

    int min_length = j - i;
    string min_string = s.substr(i, min_length);

    while (j <= s.size()) {
      if (t_lookup.find(s[i]) == t_lookup.end()) {
        i++;
      }
      else if (char_table[s[i]] > t_count[s[i]]) {
        char_table[s[i]]--;
        i++;
      }
      else {
        if (j < s.size() && t_lookup.find(s[j]) != t_lookup.end()) {
          char_table[s[j]]++;
        }
        j++;
      }

      if (j <= s.size() && j - i < min_length) {
        min_length = j - i;
        min_string = s.substr(i, min_length);
      }
    }

    return min_string;

  }
};

int main(void) {
  Solution sol;
  string s = "bdab";
  string t = "ab";
  cout << sol.minWindow(s, t) << endl;
}
