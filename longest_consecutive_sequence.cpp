#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, pair<int, int>> lcs_map;
    if (nums.size() == 0) {
      return 0;
    }

    int largest_size = 1;
    for (int num : nums) {
      if (lcs_map.find(num) != lcs_map.end()) {
        continue;
      }
      if (lcs_map.find(num - 1) == lcs_map.end()
          && lcs_map.find(num + 1) == lcs_map.end()) {
        lcs_map[num] = pair<int, int>(1, 1);
      }
      else {
        int first = 1;
        int second = 1;
        if (lcs_map.find(num - 1) != lcs_map.end() &&
          lcs_map.find(num + 1) != lcs_map.end()) {
          first = lcs_map[num + 1].first + 1;
          second = lcs_map[num - 1].second + 1;

          int temp = first + second - 1;
          lcs_map[num - (second - 1)].first = temp;
          lcs_map[num + (first - 1)].second = temp;
          if (temp > largest_size) {
            largest_size = temp;
          }
        }
        else if (lcs_map.find(num - 1) != lcs_map.end()) {
          second = lcs_map[num - 1].second + 1;
          lcs_map[num - (second - 1)].first = second;
          if (second > largest_size) {
            largest_size = second;
          }

        }
        else if (lcs_map.find(num + 1) != lcs_map.end()) {
          first = lcs_map[num + 1].first + 1;
          lcs_map[num + (first - 1)].second = first;
          if (first > largest_size) {
            largest_size = first;
          }
        }
        lcs_map[num] = pair<int, int>(first, second); 
      }
    }

    return largest_size;
  }
};

int main(void) {
  Solution sol;
  vector<int> nums = {1, 6, 3, 2, 5, 8, 7, 1, 2, 4, 9};
  cout << sol.longestConsecutive(nums) << endl;

}
