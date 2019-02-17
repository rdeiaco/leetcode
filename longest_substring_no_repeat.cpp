#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int visited[256];
      for (int i = 0; i < 256; i++) {
        visited[i] = -1;
      }

      int max_len = 0;
      int current_len = 0;
      int current_start = 0;
      for (int i = 0; i < s.size(); i++) {
        if (visited[static_cast<int>(s[i])] < current_start) {
          visited[static_cast<int>(s[i])] = i;
          current_len++;
        } 
        else {
          current_start = visited[static_cast<int>(s[i])] + 1;
          current_len = i - current_start + 1;
          visited[static_cast<int>(s[i])] = i;
        }

        max_len = max(max_len, current_len);

      }

      return max_len;

    }
};

int main(void) {
  Solution sol;
  cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n";
  cout << sol.lengthOfLongestSubstring("bbbbb") << "\n";
  cout << sol.lengthOfLongestSubstring("pwwkew") << "\n";

}
