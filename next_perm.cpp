#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    if (nums.size() < 2) {
      return;
    }

    int i;
    for (i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        break;
      }
    }

    if (i >= 0) {
      int j;
      int min_valid = nums[i + 1];
      int min_index = i + 1;
      for (j = i + 2; j < nums.size(); j++) {
        if (nums[j] > nums[i] && nums[j] < min_valid) {
          min_valid = nums[j];
          min_index = j;
        }
      }

      int temp = nums[i];
      nums[i] = nums[min_index];
      nums[min_index] = temp;
    }

    sort(nums.begin() + i + 1, nums.end()); 

  }
};

int main(void) {
  Solution sol;

  vector<int> nums = {1, 2, 3, 4};
  for (int i = 0; i < 25; i++) {
    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
    sol.nextPermutation(nums);
  }
}
