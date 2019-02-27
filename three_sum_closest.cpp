#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int closest_sum = INT_MAX;
    int closest_diff = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      int j = 0;
      int k = nums.size() - 1;
      while (j < k) {
        if (j == i) {
          j++;
          continue;
        }
        if (k == i) {
          k--;
          continue;
        }

        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) {
          return target;
        }
        if (sum < target) {
          j++;
        }
        else if (sum > target) {
          k--;
        }
        
        int diff = abs(sum - target);
        if (diff < closest_diff) {
          closest_diff = diff;
          closest_sum = sum;
        }
      }
    }

    return closest_sum;
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {-1, 2, 1, -4};
  cout << sol.threeSumClosest(nums, 1) << endl;
}
