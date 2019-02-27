#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> result;
    if (nums.size() == 0) {
      return result;
    }
    if (nums.size() == 1) {
      result.push_back(to_string(nums[0]));
      return result;
    }

    int start_index = 0;
    int end_index = 0;
    int prev_val = nums[0];
    for (int i = 1; i <= nums.size(); i++) {
      if (i == nums.size() || nums[i] != prev_val + 1) {
        if (end_index == start_index) {
          result.push_back(to_string(nums[start_index])); 
        }
        else {
          result.push_back(to_string(nums[start_index]) + 
            "->" + to_string(nums[end_index]));
        }
        if (i < nums.size()) {
          start_index = i;
          end_index = i;
          prev_val = nums[i];
        }
      }
      else {
        prev_val = nums[i];
        end_index = i;
      }
    }

    return result;
  }

};

int main(void) {
  Solution sol;

  vector<int> nums = {0, 1, 2, 4, 5, 7};
  vector<string> result = sol.summaryRanges(nums);
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;

  nums = {0, 2, 3, 4, 6, 8, 9};
  result = sol.summaryRanges(nums);
  for (string s : result) {
    cout << s << " ";
  }
  cout << endl;


}
