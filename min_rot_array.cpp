#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;
    int i = (end - start) / 2;

    while (start <= end) {
      if (start == end) {
        return nums[start];
      }
      else if (nums[i] > nums[end]) {
        start = i + 1;
      }
      else {
        end = i;
      }

      i = start + (end - start) / 2;
    }

    return nums[start];
  }
  
};

int main(void) {
  Solution sol;

  vector<int> nums = {3, 4, 5, 1, 2};
  cout << sol.findMin(nums) << endl;
  nums = {4, 5, 6, 7, 0, 1, 2};
  cout << sol.findMin(nums) << endl;
  nums = {3};
  cout << sol.findMin(nums) << endl;
  nums = {3, 4};
  cout << sol.findMin(nums) << endl;
  nums = {4, 3};
  cout << sol.findMin(nums) << endl;
  nums = {4, 5, 6, -1, 0, 1, 2};
  cout << sol.findMin(nums) << endl;

}
