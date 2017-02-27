#include <vector>
#include <iostream>

class Solution {
  public:
  std::vector< std::vector<int> > subsets(std::vector<int> &nums) {
    std::vector< std::vector<int> > result;

    // Base case, empty input.
    if (nums.empty()) {
      std::vector<int> empty;
      result.push_back(empty);
      return result;
    }

    // Else, append first value in list to a duplicate of the rest of the 
    // entries in the subset vector.
    // It is assumed that the input is a set of distinct integers, so no duplicates.
    int to_append = nums[0];
    nums.erase(nums.begin()); 
    return append(to_append, subsets(nums));
  }

  std::vector< std::vector<int> > append(int to_append, std::vector< std::vector<int> > result) {
    std::vector<int> to_push;
    int i, size;
    size = result.size();

    for (i = 0; i < size; i++) {
      to_push = result[i];
      to_push.push_back(to_append);
      result.push_back(to_push);
    }

    return result;
  }

};

int main(void) {
  std::vector<int> nums;
  Solution sol;

  for (int i = 1; i < 5; i++) {
    nums.push_back(i);
  }

  std::vector< std::vector<int> > result = sol.subsets(nums);

  for (int i = 0; i < result.size(); i++) {
    if (result[i].empty()) {
      std::cout << "_";
    }
    else {
      for (int j = 0; j < result[i].size(); j++) {
        std::cout << result[i][j];
      }
    }
    std::cout << '\n';
  }

}
