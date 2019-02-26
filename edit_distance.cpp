#include <string>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {

    int prev_row[word2.size() + 1] = {0};
    for (int i = 0; i <= word1.size(); i++) {
      int prev = 0;
      for (int j = 0; j <= word2.size(); j++) {
        int dist = INT_MAX;
        if (i == 0 && j == 0) {
          dist = 0;
        }
        else if (i > 0 && j > 0) {
          if (word1[i - 1] == word2[j - 1]) {
            dist = min(dist, prev_row[j - 1]);
          }
          else {
            dist = min(dist, 1 + prev_row[j - 1]);
          }
        }
        if (j > 0) {
          dist = min(dist, 1 + prev);
        }
        if (i > 0) {
          dist = min(dist, 1 + prev_row[j]);
        }

        if (j > 0) {
          prev_row[j - 1] = prev;
        }
        prev = dist;
      }
      prev_row[word2.size()] = prev;
    }

    return prev_row[word2.size()];
  }
};

int main(void) {
  Solution sol;
  cout << sol.minDistance("auftrlda", "australia") << endl;
}

