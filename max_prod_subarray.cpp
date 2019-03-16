#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.size() < 1) {
      return 0;
    }
    int max_prev = nums[0];
    int min_prev = nums[0];
    int max_prod = nums[0];


    for (int i = 1; i < nums.size(); i++) {
      int temp = max(nums[i], max(max_prev * nums[i], min_prev * nums[i]));
      min_prev = min(nums[i], min(max_prev * nums[i], min_prev * nums[i]));
      max_prev = temp;
      max_prod = max(max_prod, max_prev);
    }

    return max_prod;
    
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {2, 3, -2, 4};
  cout << sol.maxProduct(nums) << endl;
  nums = {-2, 0, -1};
  cout << sol.maxProduct(nums) << endl;

}
