#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0;
    int j = height.size() - 1;

    int max_area = 0;
    while (i < j) {
      max_area = max((j - i) * min(height[i], height[j]), max_area);

      int i_new = i + 1;
      int j_new = j - 1;
      if (height[i] < height[j]) {
        while (height[i] > height[i_new] && i_new < j) {
          i_new++;
        }

        i = i_new;
      }
      else {
        while (height[j] > height[j_new] && j_new > i) {
          j_new--;
        }

        j = j_new;
      }
    }

    return max_area;
  }
};

int main(void) {
  Solution sol;
  vector<int> heights = {1, 8, 6, 100, 5, 4, 101, 3, 100};

  cout << sol.maxArea(heights) << endl;
}
