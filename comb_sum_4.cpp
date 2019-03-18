#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    long int sum_map[target + 1] = {0};
    // If a num matches target directly, it will look to the
    // zeroth element. To capture the singleton sequence, this should
    // be a one.
    sum_map[0] = 1;

    for (int i = 1; i <= target; i++) {
      long int seq_count = 0;

      for (int num : nums) {
        if (i - num < 0) {
          continue;
        }
        else {
          seq_count += sum_map[i - num];
          if (seq_count > INT_MAX) {
            seq_count = INT_MAX;
          }
        }
      }
      
      sum_map[i] = seq_count;
    }

    return static_cast<int>(sum_map[target]);

  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {3, 33, 333};
  cout << sol.combinationSum4(nums, 10000) << endl;
}
