#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    if (nums.size() == 0) {
      return;
    }
    int zero_index = 0;
    int two_index = nums.size() - 1;
    int i = 0;
    while (i <= two_index) {
      if (nums[i] == 0) {
        int temp = nums[i];
        nums[i] = nums[zero_index];
        nums[zero_index] = temp;
        zero_index++;
        i++;
      }
      else if (nums[i] == 2) {
        int temp = nums[i];
        nums[i] = nums[two_index];
        nums[two_index] = temp;
        two_index--;
      }
      else {
        i++;
      }
    }
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {1, 1, 1, 0, 2, 2, 0, 1, 0, 0, 2, 1, 1, 2, 1};
  sol.sortColors(nums);
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
}
