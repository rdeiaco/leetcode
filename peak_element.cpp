#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int lower = 0;
    int upper = nums.size();

    while (lower < upper) {
      int mid = (upper - lower) / 2 + lower;
      bool prev_lower, next_lower;

      if (mid == nums.size() - 1) {
        next_lower = true;
      }
      else {
        next_lower = nums[mid + 1] < nums[mid];
      }
      if (mid == 0) {
        prev_lower = true;
      }
      else {
        prev_lower = nums[mid - 1] < nums[mid];
      }

      if (prev_lower && next_lower) {
        return mid;
      }
      else if (!next_lower) {
        lower = mid + 1;
      }
      else {
        upper = mid;
      }
    }

    return -1;
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  cout << sol.findPeakElement(nums) << endl;
}
