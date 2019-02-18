#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int max_height = 0;
    for (int h : height) {
      max_height = max(max_height, h);
    }

    int water_count = 0;
    for (int i = 1; i <= max_height; i++) {
      bool left_found = false;
      int left_index, right_index;

      for (int j = 0; j < height.size(); j++) {
        if (height[j] >= i) {
          if (!left_found) {
            left_found = true;
            left_index = j;
          }
          right_index = j;
        }
      }

      if (right_index - left_index < 2) {
        return water_count;
      }

      for (int j = left_index + 1; j < right_index; j++) {
        if (height[j] < i) {
          water_count++;
        }
      }
    }

    return water_count;

  }
};

int main(void) {
  Solution sol;
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sol.trap(height) << "\n";
  height = {};
  cout << sol.trap(height) << "\n";
}
