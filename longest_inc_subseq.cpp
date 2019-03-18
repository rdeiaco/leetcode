#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return 1;
    }

    vector<int> lut(nums.size(), 1);
    int max_subseq_len = 1;

    for (int j = nums.size() - 2; j >= 0; j--) {
      for (int i = j + 1; i < nums.size(); i++) {
        if (nums[i] > nums[j]) {
          lut[j] = max(lut[j], lut[i] + 1);
        }  
      }
      max_subseq_len = max(max_subseq_len, lut[j]);
    }

    return max_subseq_len;

  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << sol.lengthOfLIS(nums) << endl;
}
