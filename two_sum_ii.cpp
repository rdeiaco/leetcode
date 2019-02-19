#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> remainder_map;
    vector<int> target_indices = vector<int>(2);

    for (int i = 1; i < numbers.size(); i++) {
      int sum = numbers[0] + numbers[i];
      if (sum == target) {
        target_indices[0] = 1;
        target_indices[1] = i+1; 
        return target_indices;
      }
      if (sum > target) {
        break;
      }
      remainder_map[target - sum] = i;
    }

    for (int i = 1; i < numbers.size(); i++) {
      int search_key = numbers[i] - numbers[0];
      if (remainder_map.find(search_key) != remainder_map.end()) {
        target_indices[0] = min(remainder_map[search_key] + 1, i + 1);
        target_indices[1] = max(remainder_map[search_key] + 1, i + 1);
        return target_indices;
      }
    }

    target_indices[0] = 0;
    target_indices[1] = 0;
    return target_indices;
    
  }
};

int main(void) {
  Solution sol;
  vector<int> numbers = {5, 25, 75};
  int target = 100;
  vector<int> result = sol.twoSum(numbers, target);
  for (int i : result) {
    cout << i << endl;
  }
}
