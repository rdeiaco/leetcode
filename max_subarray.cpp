#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_sum = nums[nums.size() - 1];
    for (int j = nums.size() - 2; j >= 0; j--) {
      nums[j] = max(nums[j + 1] + nums[j], nums[j]);
      if (nums[j] > max_sum) {
        max_sum = nums[j];
      }
    }

    return max_sum;
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {-2, -1, -3, -4, -1, -2, -1, -5, -40};
  cout << sol.maxSubArray(nums) << endl;
}
