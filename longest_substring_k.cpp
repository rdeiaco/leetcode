#include <string>
#include <vector>
#include <iostream>

class Solution {
  public:
  int longestSubstring(std::string s, int k) {
    int alpha_count[26] = {0};

    // Return zero for the empty string, base case.
    if (s.empty()) {
      return 0;
    }

    // Get a count for each letter in the string.
    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
      alpha_count[*it - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if ((alpha_count[i] > 0) && (alpha_count[i] < k)) {
        std::vector<std::string> splits = split_string(s, 'a' + i);
        int max = 0;
        int temp;
        
        // Break the problem into substrings if it contains characters that appear at least once
        // but fewer than k times. Then, find the largest result of the subproblems. 
        // If there is more than one character that satisfies this, take care of the first one and
        // the rest will necessarily be handled in the smaller sub-problems.
        for (std::vector<std::string>::iterator it = splits.begin(); it != splits.end(); it++) {
          temp = longestSubstring(*it, k);
          if (temp > max) {
            max = temp;
          }
        }
        return max;
      }
    }

    // Otherwise, the whole string satisfies the problem.
    return s.length(); 
  }

  // Helper that splits the string based on a given character delimiter.
  std::vector<std::string> split_string(std::string s, char delim) {
    std::vector<std::string> splits;
    int i = 0;
    splits.push_back("");

    for (std::string::iterator it = s.begin(); it != s.end(); it++) {
      if (*it == delim) {
        splits.push_back("");
        i++; 
      }
      else {
        splits[i].append(1U, *it);
      }
    }

    return splits;
  }
};


int main(void) {
  Solution sol;
  std::cout << sol.longestSubstring("abbcbbddddceeee", 3) << '\n';
  return 0;
}
