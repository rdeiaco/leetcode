#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end());

    int j = citations.size() - 1;
    for (int h = citations.size(); h >= 0; h--) {
      while (j >= 0 && citations[j] > h) {
        j--;
      }

      int above_count = citations.size() - j - 1; 
      int below_count = j + 1;

      if (above_count == h && below_count == citations.size() - h) {
        return h;
      }

      while (j >= 0 && citations[j] == h) {
        j--;
        above_count = citations.size() - j - 1; 
        below_count = j + 1;

        if (above_count == h && below_count == citations.size() - h) {
          return h;
        }
      }
    }

    return 0;
  }
};


int main(void) {
  Solution sol;
  vector<int> citations = {0, 0, 0, 0, 0, 1};
  cout << sol.hIndex(citations) << endl;

}

