#include <vector>

class Solution {
  public:
  vector<int> countBits(int num) {
    int i, j;
    int count;
    std::vector<int> result;

    for (i = 0; i <= num; i++) {
      count = 0;
      for (j = 0; j < 32; j++) {
        if ((i>>j) & 0x1) {
          count++;
        }
      }
      result.push_back(count);
    }

    return result;
  }
};
