#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }

    int dp[nums.size()][nums.size()] = {0};
    memset(dp, 0, sizeof(int) * nums.size() * nums.size());

    for (int right = 0; right < nums.size(); right++) {
      for (int left = right; left >= 0; left--) {
        for (int k = left; k <= right; k++) {
          int left_term = left > 0 ? nums[left - 1] : 1;
          int right_term = right < nums.size() - 1 ? nums[right + 1] : 1;
          int left_seq_max = k > left ? dp[left][k - 1] : 0;
          int right_seq_max = k < right ? dp[k + 1][right] : 0;
          dp[left][right] = max(dp[left][right], left_term * nums[k] * right_term 
            + left_seq_max + right_seq_max);
        }
      }
    }

    return dp[0][nums.size() - 1];
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {3, 1, 5, 8};

  cout << sol.maxCoins(nums) << endl;

}
